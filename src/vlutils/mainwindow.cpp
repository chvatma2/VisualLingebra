#include "mainwindow.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi();
}

void CMainWindow::setupUi()
{
    m_file.setTitle(tr("File"));
    m_tools.setTitle(tr("Tools"));
    m_help.setTitle(tr("Help"));
    m_menuBar.addMenu(&m_file);
    m_menuBar.addMenu(&m_tools);
    m_menuBar.addMenu(&m_help);
    setMenuBar(&m_menuBar);

    m_tabBar.addTab("TEST");
    m_tabBar.addTab("TEST2");
    m_mainLayout.addWidget(&m_tabBar, 0, Qt::AlignTop);
    m_centralWidget.setLayout(&m_mainLayout);
    setCentralWidget(&m_centralWidget);
}
