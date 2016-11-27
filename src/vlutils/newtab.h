#ifndef CNEWTAB_H
#define CNEWTAB_H

#include <QWidget>
#include <QLabel>
#include <QTreeView>

class CNewTab : public QWidget
{
public:
    CNewTab(QWidget *parent = 0);

private:
    QLabel m_selectionLabel;
    QTreeView * m_view = nullptr;

private slots:
    void treeViewItemSelected();
};

#endif // CNEWTAB_H
