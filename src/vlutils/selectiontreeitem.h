#ifndef CSELECTIONTREEITEM_H
#define CSELECTIONTREEITEM_H

#include <QList>
#include <QVariant>

class CSelectionTreeItem
{
public:
    CSelectionTreeItem(const QList<QVariant> &data, CSelectionTreeItem* parent = nullptr);
    ~CSelectionTreeItem();

    void addChild(CSelectionTreeItem* child);
    CSelectionTreeItem *parent();
    CSelectionTreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;

private:
    CSelectionTreeItem* m_parent = nullptr;
    QList<CSelectionTreeItem*> m_children;
    QList<QVariant> m_itemData;
};

#endif // CSELECTIONTREEITEM_H
