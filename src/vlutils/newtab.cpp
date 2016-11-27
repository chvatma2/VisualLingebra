#include "newtab.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTreeView>

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
    leftLayout->addWidget(&m_selectionLabel);
    leftLayout->addWidget(new QTreeView);
    leftLayout->addStretch();
    layout->addLayout(centerLayout, 2);
    layout->addLayout(rightLayout, 1);
}
