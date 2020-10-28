#include "ut_itemwidget_test.h"

#define private public
#include "itemwidget.h"
#undef private

//Google GTest 相关头文件
#include <gtest/gtest.h>

//Qt单元测试相关头文件
#include <QTest>
#include <QtGui>
#include <QSignalSpy>
#include <QDebug>
#include <QMainWindow>
#include <DTitlebar>

DWIDGET_USE_NAMESPACE

UT_ItemWidget_Test::UT_ItemWidget_Test()
{
}

void UT_ItemWidget_Test::SetUp()
{
}

void UT_ItemWidget_Test::TearDown()
{
}

#ifdef UT_ITEMWIDGET_TEST

TEST_F(UT_ItemWidget_Test, setIcon)
{
    ItemWidget *itemWidget = new ItemWidget(ItemFuncType::ItemFuncType_Item, nullptr);
    EXPECT_NE(itemWidget, nullptr);
    itemWidget->setIcon("deepin-terminal");

#ifdef ENABLE_UI_TEST
    QTest::qWait(UT_WAIT_TIME);
#endif
    delete itemWidget;
}

TEST_F(UT_ItemWidget_Test, setFuncIcon)
{
    ItemWidget *itemWidget = new ItemWidget(ItemFuncType::ItemFuncType_Item, nullptr);
    EXPECT_NE(itemWidget, nullptr);
    itemWidget->setFuncIcon(ItemFuncType::ItemFuncType_Group);

#ifdef ENABLE_UI_TEST
    QTest::qWait(UT_WAIT_TIME);
#endif
    delete itemWidget;
}

TEST_F(UT_ItemWidget_Test, setText)
{
    ItemWidget *itemWidget = new ItemWidget(ItemFuncType::ItemFuncType_Item, nullptr);
    EXPECT_NE(itemWidget, nullptr);

    QString firstText = "name";
    QString secondText = "content";
    itemWidget->setText(firstText, secondText);

    EXPECT_EQ(itemWidget->m_firstText, firstText);
    EXPECT_EQ(itemWidget->m_secondText, secondText);

#ifdef ENABLE_UI_TEST
    QTest::qWait(UT_WAIT_TIME);
#endif
    delete itemWidget;
}

TEST_F(UT_ItemWidget_Test, isEqual)
{
    ItemWidget *itemWidget = new ItemWidget(ItemFuncType::ItemFuncType_Item, nullptr);
    EXPECT_NE(itemWidget, nullptr);

    QString firstText = "isEqual";
    itemWidget->setText(firstText);

    bool isEqual = itemWidget->isEqual(ItemFuncType_Item, firstText);
    EXPECT_EQ(isEqual, true);

    isEqual = itemWidget->isEqual(ItemFuncType_Group, firstText);
    EXPECT_EQ(isEqual, false);

    firstText = "NotEqual";
    isEqual = itemWidget->isEqual(ItemFuncType_Group, firstText);
    EXPECT_EQ(isEqual, false);

#ifdef ENABLE_UI_TEST
    QTest::qWait(UT_WAIT_TIME);
#endif
    delete itemWidget;
}

TEST_F(UT_ItemWidget_Test, getFocus)
{
    ItemWidget *itemWidget = new ItemWidget(ItemFuncType::ItemFuncType_Item, nullptr);
    EXPECT_NE(itemWidget, nullptr);

    itemWidget->getFocus();

#ifdef ENABLE_UI_TEST
    QTest::qWait(UT_WAIT_TIME);
#endif
    delete itemWidget;
}

TEST_F(UT_ItemWidget_Test, lostFocus)
{
    ItemWidget *itemWidget = new ItemWidget(ItemFuncType::ItemFuncType_Item, nullptr);
    EXPECT_NE(itemWidget, nullptr);

    itemWidget->lostFocus();

#ifdef ENABLE_UI_TEST
    QTest::qWait(UT_WAIT_TIME);
#endif
    delete itemWidget;
}

TEST_F(UT_ItemWidget_Test, setFont)
{
    ItemWidget *itemWidget = new ItemWidget(ItemFuncType::ItemFuncType_Item, nullptr);
    EXPECT_NE(itemWidget, nullptr);

    itemWidget->setFont(itemWidget->m_firstline, DFontSizeManager::T7, ItemTextColor_Text);
    EXPECT_EQ(itemWidget->m_firstline->font().pixelSize(), DFontSizeManager::instance()->fontPixelSize(DFontSizeManager::T7));

    itemWidget->setFont(itemWidget->m_secondline, DFontSizeManager::T8, ItemTextColor_TextTips);
    EXPECT_EQ(itemWidget->m_secondline->font().pixelSize(), DFontSizeManager::instance()->fontPixelSize(DFontSizeManager::T8));

#ifdef ENABLE_UI_TEST
    QTest::qWait(UT_WAIT_TIME);
#endif
    delete itemWidget;
}

TEST_F(UT_ItemWidget_Test, setFontSize)
{
    ItemWidget *itemWidget = new ItemWidget(ItemFuncType::ItemFuncType_Item, nullptr);
    EXPECT_NE(itemWidget, nullptr);

    itemWidget->setFontSize(itemWidget->m_firstline, DFontSizeManager::T6);
    EXPECT_EQ(itemWidget->m_firstline->font().pixelSize(), DFontSizeManager::instance()->fontPixelSize(DFontSizeManager::T6));

    itemWidget->setFontSize(itemWidget->m_secondline, DFontSizeManager::T9);
    EXPECT_EQ(itemWidget->m_secondline->font().pixelSize(), DFontSizeManager::instance()->fontPixelSize(DFontSizeManager::T9));

#ifdef ENABLE_UI_TEST
    QTest::qWait(UT_WAIT_TIME);
#endif
    delete itemWidget;
}

TEST_F(UT_ItemWidget_Test, setFontColor)
{
    ItemWidget *itemWidget = new ItemWidget(ItemFuncType::ItemFuncType_Item, nullptr);
    EXPECT_NE(itemWidget, nullptr);

    itemWidget->setFontColor(itemWidget->m_firstline, ItemTextColor::ItemTextColor_Text);
    DPalette firstPalette = DApplicationHelper::instance()->palette(itemWidget->m_firstline);
    EXPECT_EQ(firstPalette.color(DPalette::Text), itemWidget->getColor(ItemTextColor::ItemTextColor_Text));

    itemWidget->setFontColor(itemWidget->m_secondline, ItemTextColor::ItemTextColor_TextTips);
    DPalette secondPalette = DApplicationHelper::instance()->palette(itemWidget->m_secondline);
    EXPECT_EQ(secondPalette.color(DPalette::Text), itemWidget->getColor(ItemTextColor::ItemTextColor_TextTips));

#ifdef ENABLE_UI_TEST
    QTest::qWait(UT_WAIT_TIME);
#endif
    delete itemWidget;
}

TEST_F(UT_ItemWidget_Test, getColor)
{
    ItemWidget *itemWidget = new ItemWidget(ItemFuncType::ItemFuncType_Item, nullptr);
    EXPECT_NE(itemWidget, nullptr);

    delete itemWidget;
#ifdef ENABLE_UI_TEST
    QTest::qWait(UT_WAIT_TIME);
#endif
}
//// 设置文字
//void setText(const QString &firstline, const QString &secondline = "");
//// 是否匹配
//bool isEqual(ItemFuncType type, const QString &key);
//// 获取焦点
//void getFocus();
//// 丢失焦点
//void lostFocus();

//// 设置文字大小和颜色
//void setFont(DLabel *label, DFontSizeManager::SizeType fontSize, ItemTextColor colorType);
//// 设置字体大小
//void setFontSize(DLabel *label, DFontSizeManager::SizeType fontSize);
//// 设置字体颜色
//void setFontColor(DLabel *label, ItemTextColor colorType);
//// 返回指定颜色值
//QColor getColor(ItemTextColor colorType);
//// 处理键盘事件
//void rightKeyPress();
//// 项被点击
//void onItemClicked();

#endif
