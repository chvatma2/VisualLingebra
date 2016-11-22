#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include "vlutils_global.h"
#include "tabbar.h"

#include <QMainWindow>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QWidget>

class VLUTILSSHARED_EXPORT CMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CMainWindow(QWidget *parent = 0);

signals:

public slots:

private:
    void setupUi();

    QMenuBar m_menuBar;
    QMenu m_tools;
    QMenu m_help;
    QMenu m_file;
    CTabBar m_tabBar;
    QVBoxLayout m_mainLayout;
    QWidget m_centralWidget;
};

#endif // CMAINWINDOW_H
