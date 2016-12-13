#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include "vlutils_global.h"
#include "tabbar.h"
#include "menubar.h"
#include "newtab.h"

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QHash>
#include <QTranslator>

//TODO
//1. Options
//2. Zmena jazyka

class VLUTILSSHARED_EXPORT CMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

signals:

public slots:

private:
    void setupUi();
    void addNewTab();
    void closeCurrent();
    void loadLanguages();
    void retranslateUi();

    CMenuBar m_menuBar;
    CTabBar *m_tabWidget;
    QHash<QString, QTranslator> m_languageMap;

private slots:
    void onOpenTask(Tasks task);
    void onLastTabClosed();
};

#endif // CMAINWINDOW_H
