#include "selectiontreeitem.h"

CSelectionTreeItem::CSelectionTreeItem(const QList<QVariant> &data, CSelectionTreeItem *parent)
    : m_parent(parent), m_itemData(data)
{

}

CSelectionTreeItem::~CSelectionTreeItem()
{
    qDeleteAll(m_children);
}

void CSelectionTreeItem::addChild(CSelectionTreeItem *child)
{
    m_children.push_back(child);
}

CSelectionTreeItem *CSelectionTreeItem::parent()
{
    return m_parent;
}

CSelectionTreeItem *CSelectionTreeItem::child(int row)
{
    return m_children.value(row);
}

int CSelectionTreeItem::childCount() const
{
    return m_children.size();
}

int CSelectionTreeItem::columnCount() const
{
    return m_itemData.size();
}

QVariant CSelectionTreeItem::data(int column) const
{
    return m_itemData.value(column);
}

int CSelectionTreeItem::row() const
{
    if (m_parent)
        return m_parent->m_children.indexOf(const_cast<CSelectionTreeItem*>(this));

    return 0;
}
