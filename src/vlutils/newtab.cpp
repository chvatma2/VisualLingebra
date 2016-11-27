#include "newtab.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

#include "selectiontreemodel.h"

CNewTab::CNewTab(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout;
    setLayout(layout);
    QVBoxLayout *leftLayout = new QVBoxLayout;
    QVBoxLayout *centerLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;
    layout->addLayout(leftLayout, 1);

    m_selectionLabel.setText(tr("Select assignement"));
    QFont font;
    font.setPointSize(18);
    font.setBold(true);
    m_selectionLabel.setFont(font);

    m_view = new QTreeView;
    CSelectionTreeModel *model = new CSelectionTreeModel;
    m_view->setModel(model);
    m_view->setIndentation(8);

    leftLayout->addWidget(&m_selectionLabel);
    leftLayout->addWidget(m_view);
    leftLayout->addStretch();
    layout->addLayout(centerLayout, 2);
    layout->addLayout(rightLayout, 1);

    connect(m_view->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CNewTab::treeViewItemSelected);

}

void CNewTab::treeViewItemSelected()
{
    QModelIndex currentSelection = m_view->selectionModel()->currentIndex();
    qDebug() << currentSelection.data();
}
