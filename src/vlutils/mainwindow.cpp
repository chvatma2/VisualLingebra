#include "mainwindow.h"

#include "newtab.h"
#include "taskwidget.h"

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

    resize(1024, 768);
    m_tabWidget = new CTabBar(this);

    addNewTab();

    setCentralWidget(m_tabWidget);

    connect(&m_menuBar, &CMenuBar::newTaskClicked, this, &CMainWindow::addNewTab);
}

void CMainWindow::addNewTab()
{
    CNewTab *newTab = new CNewTab;
    newTab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    int index = m_tabWidget->addTab(newTab, QIcon(), "New");
    connect(newTab, &CNewTab::openTask, this, &CMainWindow::onOpenTask);
    m_tabWidget->setCurrentIndex(index);
}

void CMainWindow::onOpenTask(Tasks task)
{
    int index;
    switch(task) {
    case Tasks::MOVEMENT2D:
        index = m_tabWidget->addTab(new CTaskWidget(), QIcon(), tr("2D Movement"));
        break;
    case Tasks::INDEPENDENCE:
        index = m_tabWidget->addTab(new CTaskWidget(), QIcon(), tr("Linear independence"));
        break;
    case Tasks::HAMMING:
        index = m_tabWidget->addTab(new CTaskWidget(), QIcon(), tr("Hamming code"));
        break;
    default:
        qDebug() << "Unhandled task type";
        break;
    }
    m_tabWidget->setCurrentIndex(index);
}
