#include "selectiontreemodel.h"


CSelectionTreeModel::CSelectionTreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << tr("Title");
    m_rootItem = new CSelectionTreeItem(rootData);

    setupModelData();
}

CSelectionTreeModel::~CSelectionTreeModel()
{
    delete m_rootItem;
}

QModelIndex CSelectionTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    CSelectionTreeItem *parentItem;

    if (!parent.isValid())
        parentItem = m_rootItem;
    else
        parentItem = static_cast<CSelectionTreeItem*>(parent.internalPointer());

    CSelectionTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex CSelectionTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    CSelectionTreeItem *childItem = static_cast<CSelectionTreeItem*>(index.internalPointer());
    CSelectionTreeItem *parentItem = childItem->parent();

    if (parentItem == m_rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int CSelectionTreeModel::rowCount(const QModelIndex &parent) const
{
    CSelectionTreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = m_rootItem;
    else
        parentItem = static_cast<CSelectionTreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int CSelectionTreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<CSelectionTreeItem*>(parent.internalPointer())->columnCount();
    else
        return m_rootItem->columnCount();
}

QVariant CSelectionTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    CSelectionTreeItem *item = static_cast<CSelectionTreeItem*>(index.internalPointer());

    switch(role) {
    case Qt::DisplayRole:
        return item->data(0);
    case Qt::WhatsThisRole:
        return item->data(1);
    default:
        return QVariant();
    }
}

QVariant CSelectionTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return m_rootItem->data(section);

    return QVariant();
}

Qt::ItemFlags CSelectionTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

void CSelectionTreeModel::setupModelData()
{
    QList<QVariant> ladata;
    ladata << "Linear Algebra" << "";
    QList<QVariant> movdata;
    movdata << "2D Movement" << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                                "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                                "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
                                "nisi ut aliquip ex ea commodo consequat.";
    QList<QVariant> hamdata;
    hamdata << "Hamming Code" << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                                 "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                                 "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. "
                                 "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. "
                                 "Excepteur sint occaecat cupidatat non proident, "
                                 "sunt in culpa qui officia deserunt mollit anim id est laborum.";
    QList<QVariant> lidata;
    lidata << "Linear Independence" << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                                       "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    CSelectionTreeItem* linearAlgebra = new CSelectionTreeItem(ladata, m_rootItem);
    CSelectionTreeItem* movement2D = new CSelectionTreeItem(movdata, linearAlgebra);
    CSelectionTreeItem* hamming = new CSelectionTreeItem(hamdata, linearAlgebra);
    CSelectionTreeItem* linearIndependence = new CSelectionTreeItem(lidata, linearAlgebra);


    linearAlgebra->addChild(movement2D);
    linearAlgebra->addChild(hamming);
    linearAlgebra->addChild(linearIndependence);
    m_rootItem->addChild(linearAlgebra);
}
