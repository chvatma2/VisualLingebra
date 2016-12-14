#include "tabbar.h"
#include "tabs.h"

#include <QTabBar>
#include <QDebug>

CTabBar::CTabBar(QWidget *parent) : QTabWidget(parent)
{
    setTabsClosable(true);
    setMovable(true);
    tabBar()->setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);

    connect(this, &CTabBar::tabCloseRequested, this, &CTabBar::onTabClosed);
}

void CTabBar::retranslateUi()
{
    for(int i = 0; i < count(); ++i) {
        QString old = ((ITabs*)widget(i))->getName();
        if(old == "2D Movement") {
            setTabText(i, tr("2D Movement"));
        } else if (old == "Linear independence"){
            setTabText(i, tr("Linear independence"));
        } else if (old == "Hamming code") {
            setTabText(i, tr("Hamming code"));
        } else {
            setTabText(i, tr("New"));
        }
        ((ITabs*)widget(i))->retranslateUi();
    }
}

void CTabBar::onTabClosed(int index)
{
    QWidget* tmp = widget(index);
    removeTab(index);
    //delete tmp;
    if(count() == 0) {
        emit lastTabClosed();
    }
}
