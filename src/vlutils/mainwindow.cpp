#include "mainwindow.h"

#include "newtab.h"

#include <QDebug>

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi();
}

CMainWindow::~CMainWindow()
{
    qDebug() << "Main Window Destroyed";
}

void CMainWindow::setupUi()
{
    setMenuBar(&m_menuBar);

    m_tabBar = new CTabBar(this);

    m_centralWidget = new QWidget(this);
    m_mainLayout = new QVBoxLayout(m_centralWidget);
    m_tabBar->addTab(tr("New"));
    m_mainLayout->addWidget(m_tabBar);
    CNewTab *newTab = new CNewTab;
    newTab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_mainLayout->addWidget(newTab);

    setCentralWidget(m_centralWidget);
}
