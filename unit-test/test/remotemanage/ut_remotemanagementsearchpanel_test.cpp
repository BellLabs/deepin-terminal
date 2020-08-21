#include "ut_remotemanagementsearchpanel_test.h"

#define private public
#include "remotemanagementsearchpanel.h"
#include "service.h"
#include "mainwindow.h"
#undef public

//Google GTest 相关头文件
#include <gtest/gtest.h>

//Qt单元测试相关头文件
#include <QTest>
#include <QtGui>

UT_RemoteManagementSearchPanel_Test::UT_RemoteManagementSearchPanel_Test()
{
}

void UT_RemoteManagementSearchPanel_Test::SetUp()
{
    if (!Service::instance()->property("isServiceInit").toBool())
    {
        Service::instance()->init();
        Service::instance()->setProperty("isServiceInit", true);
    }

    m_normalTermProperty[QuakeMode] = false;
    m_normalTermProperty[SingleFlag] = true;
    m_normalWindow = new NormalWindow(m_normalTermProperty, nullptr);
}

void UT_RemoteManagementSearchPanel_Test::TearDown()
{
    delete m_normalWindow;
}

//#ifdef UT_REMOTEMANAGEMENTSEARCHPANEL_TEST
TEST_F(UT_RemoteManagementSearchPanel_Test, RemoteManagementSearchPanelTest)
{
    m_normalWindow->resize(800, 600);
    m_normalWindow->show();
    EXPECT_EQ(m_normalWindow->isVisible(), true);

    m_normalWindow->showPlugin(MainWindow::PLUGIN_TYPE_REMOTEMANAGEMENT);

    RemoteManagementPlugin *remotePlugin = m_normalWindow->findChild<RemoteManagementPlugin *>();
    RemoteManagementTopPanel *remoteTopPanel = remotePlugin->getRemoteManagementTopPanel();
    EXPECT_NE(remoteTopPanel, nullptr);
    EXPECT_EQ(remoteTopPanel->isVisible(), true);

    RemoteManagementSearchPanel *searchPanel = remoteTopPanel->findChild<RemoteManagementSearchPanel*>();
    searchPanel->clearAllFocus();

#ifdef ENABLE_UI_TEST
    QTest::qWait(1000);
#endif
}
//#endif
