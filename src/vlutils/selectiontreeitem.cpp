#include "selectiontreeitem.h"

CSelectionTreeItem::CSelectionTreeItem(const QString &title, CSelectionTreeItem *parent)
    : m_title(title), m_parent(parent)
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
