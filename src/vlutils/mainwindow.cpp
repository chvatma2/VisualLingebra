#include "mainwindow.h"

#include "newtab.h"
#include "taskwidget.h"

#include <QDebug>
#include <QDirIterator>
#include <QApplication>
#include <QTranslator>

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi();
    loadLanguages();
    m_menuBar.setLanguageList(getAvailableTranslations());
}

CMainWindow::~CMainWindow()
{
    qDebug() << "Main Window Destroyed";
    if(m_currentTranslator != nullptr) {
        delete m_currentTranslator;
    }
}

void CMainWindow::setupUi()
{
    setMenuBar(&m_menuBar);

    resize(1024, 768);
    setMinimumSize(840, 472);
    m_tabWidget = new CTabBar(this);

    addNewTab();

    setCentralWidget(m_tabWidget);

    connect(&m_menuBar, &CMenuBar::newTaskClicked, this, &CMainWindow::addNewTab);
    connect(&m_menuBar, &CMenuBar::closeCurrentClicked, this, &CMainWindow::closeCurrent);
    connect(m_tabWidget, &CTabBar::lastTabClosed, this, &CMainWindow::onLastTabClosed);
    connect(&m_menuBar, &CMenuBar::languageChanged, this, &CMainWindow::changeLanguage);
    connect(m_tabWidget, &CTabBar::currentChanged, this, &CMainWindow::onCurrentTabChanged);
}

void CMainWindow::addNewTab()
{
    CNewTab *newTab = new CNewTab;
    newTab->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    int index = m_tabWidget->addTab(newTab, QIcon(), tr("New"));
    connect(newTab, &CNewTab::openTask, this, &CMainWindow::onOpenTask);
    m_tabWidget->setCurrentIndex(index);
}

void CMainWindow::closeCurrent()
{
    m_tabWidget->removeTab(m_tabWidget->currentIndex());
}

void CMainWindow::loadLanguages()
{
    m_languageMap.insert("english", QFileInfo());
    QDirIterator iterator("../translations");
    QFileInfo fileInfo;
    while (iterator.hasNext()) {
        iterator.next();
        fileInfo = iterator.fileInfo();
        if(fileInfo.isHidden()) {
            continue;
        }
        m_languageMap.insert(fileInfo.baseName(), fileInfo);
    }

}

void CMainWindow::retranslateUi()
{
    m_menuBar.retranslateUi();
    m_tabWidget->retranslateUi();
}

QStringList CMainWindow::getAvailableTranslations()
{
    QStringList result;
    for(QString str : m_languageMap.keys()) {
        result << str;
    }
    return result;
}

void CMainWindow::changeLanguage(const QString &language)
{
    qDebug() << "New language: " << language;

    if(m_currentTranslator != nullptr) {
        if(!qApp->removeTranslator(m_currentTranslator)) {
            qDebug() << "Failed to delete translator";
        }
        delete m_currentTranslator;
    }

    if(language != "english") {
        m_currentTranslator = new QTranslator;
        m_currentTranslator->load(m_languageMap[language].absoluteFilePath());
        qApp->installTranslator(m_currentTranslator);
    } else {
        m_currentTranslator = nullptr;
        qApp->installTranslator(m_currentTranslator);
    }

    retranslateUi();
}

void CMainWindow::onOpenTask(const QString &pluginpath, const QString &name)
{
    int index = m_tabWidget->currentIndex();
    m_tabWidget->removeTab(index);
    CTaskWidget *taskWidget = new CTaskWidget(pluginpath);
    taskWidget->setName(name);
    m_tabWidget->insertTab(index, taskWidget, QIcon(), name);
    m_tabWidget->setCurrentIndex(index);
}

void CMainWindow::onLastTabClosed()
{
    addNewTab();
}

void CMainWindow::onCurrentTabChanged(int index)
{
    if(dynamic_cast<CTaskWidget*>(m_tabWidget->widget(index))) {
        m_menuBar.enableSave(true);
    } else {
        m_menuBar.enableSave(false);
    }
}
