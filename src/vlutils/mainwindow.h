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
#include <QFileInfo>
#include <QTranslator>

//TODO

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
    QStringList getAvailableTranslations();
    void changeLanguage(const QString &language);

    CMenuBar m_menuBar;
    CTabBar *m_tabWidget;
    QHash<QString, QFileInfo> m_languageMap;
    QTranslator *m_currentTranslator = nullptr;

private slots:
    void onOpenTask(const QString &pluginpath, const QString& name);
    void onLastTabClosed();
    void onCurrentTabChanged(int index);
};

#endif // CMAINWINDOW_H
