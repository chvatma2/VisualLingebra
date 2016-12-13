#ifndef CTABBAR_H
#define CTABBAR_H

#include <QTabWidget>
#include <QList>

class CTabBar : public QTabWidget
{
    Q_OBJECT
public:
    explicit CTabBar(QWidget *parent = 0);

signals:
    void lastTabClosed();

private slots:
    void onTabClosed(int index);
};

#endif // CTABBAR_H
