#ifndef CSELECTIONTREEMODEL_H
#define CSELECTIONTREEMODEL_H

#include <QAbstractItemModel>

#include "selectiontreeitem.h"

class CSelectionTreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit CSelectionTreeModel(QObject *parent = 0);
    ~CSelectionTreeModel();

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

private:
    void setupModelData();

    CSelectionTreeItem *m_rootItem;

};

#endif // CSELECTIONTREEMODEL_H
