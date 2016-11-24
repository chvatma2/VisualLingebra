#ifndef CSELECTIONTREEMODEL_H
#define CSELECTIONTREEMODEL_H

#include <QAbstractItemModel>

class CSelectionTreeModel : public QAbstractItemModel
{
public:
    explicit CSelectionTreeModel(QObject *parent = 0);

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
};

#endif // CSELECTIONTREEMODEL_H
