#include "tabbar.h"

#include <QTabBar>

CTabBar::CTabBar(QWidget *parent) : QTabWidget(parent)
{
    setTabsClosable(true);
    setMovable(true);
    tabBar()->setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);

    connect(this, &CTabBar::tabCloseRequested, this, &CTabBar::onTabClosed);
}

void CTabBar::onTabClosed(int index)
{
    QWidget* tmp = widget(index);
    removeTab(index);
    delete tmp;
}
