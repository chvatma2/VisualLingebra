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

    m_centralWidget = new QWidget(this);
    m_mainLayout = new QVBoxLayout(m_centralWidget);
    m_tabBar.addTab("TEST");
    m_tabBar.addTab("TEST2");
    m_mainLayout->addWidget(&m_tabBar, 0, Qt::AlignTop);
    m_mainLayout->addWidget(new CNewTab, 0, Qt::AlignTop);

    setCentralWidget(m_centralWidget);
}
