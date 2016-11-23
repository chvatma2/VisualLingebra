#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include "vlutils_global.h"
#include "tabbar.h"
#include "menubar.h"

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>

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

    CMenuBar m_menuBar;
    CTabBar m_tabBar;
    QWidget *m_centralWidget;
    QVBoxLayout *m_mainLayout;
};

#endif // CMAINWINDOW_H
