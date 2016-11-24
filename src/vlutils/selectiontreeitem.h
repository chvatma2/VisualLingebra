#ifndef CSELECTIONTREEITEM_H
#define CSELECTIONTREEITEM_H

#include <QList>

class CSelectionTreeItem
{
public:
    CSelectionTreeItem(const QString& title, CSelectionTreeItem* parent = nullptr);
    ~CSelectionTreeItem();

    void addChild(CSelectionTreeItem* child);

private:
    QString m_title;
    CSelectionTreeItem* m_parent;
    QList<CSelectionTreeItem*> m_children;
};

#endif // CSELECTIONTREEITEM_H
