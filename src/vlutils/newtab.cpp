#include "newtab.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QFileDialog>

#include "selectiontreemodel.h"

//TODO

CNewTab::CNewTab(QWidget *parent) : ITabs(parent)
{
    setName("New");
    m_isDescriptionPresent = false;

    QHBoxLayout *layout = new QHBoxLayout;
    setLayout(layout);

    setupLeftLayout();
    setupCenterLayout();
    setupRightLayout();

    layout->addLayout(&m_leftLayout, 1);
    layout->addLayout(&m_centerLayout, 3);
    //layout->addLayout(&m_rightLayout, 1);

    connect(m_view->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CNewTab::treeViewItemSelected);
    connect(&m_openTaskButton, &QPushButton::clicked, this, &CNewTab::onOpenTaskClicked);
    connect(&m_loadTaskButton, &QPushButton::clicked, this, &CNewTab::onLoadTaskClicked);
    m_view->expandAll();
}

void CNewTab::retranslateUi()
{
    m_selectionLabel.setText(tr("Select assignement"));
    m_selectionDescriptionLabel.setText(tr("Task overview"));
    m_openTaskButton.setText(tr("Open"));
    m_loadTaskTitle.setText(tr("Load task from file"));
    m_loadTaskButton.setText(tr("Add new task"));


    CSelectionTreeModel *model = new CSelectionTreeModel;
    m_view->setModel(model);
    connect(m_view->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CNewTab::treeViewItemSelected);
}

void CNewTab::setupLeftLayout()
{
    QFont font;
    font.setPointSize(14);
    //font.setBold(true);

    m_selectionLabel.setText(tr("Select assignement"));
    m_selectionLabel.setFont(font);

    m_view = new QTreeView;
    CSelectionTreeModel *model = new CSelectionTreeModel;
    m_view->setModel(model);
    m_view->setIndentation(8);

    m_leftLayout.addWidget(&m_selectionLabel, 0, Qt::AlignCenter | Qt::AlignTop);
    m_leftLayout.addWidget(m_view);

    m_loadTaskButton.setText(tr("Add new task"));
    m_leftLayout.addWidget(&m_loadTaskButton);
    //m_leftLayout.addStretch();
}

void CNewTab::setupCenterLayout()
{
    QFont font;
    font.setPointSize(14);

    m_selectionDescriptionLabel.setText(tr("Task overview"));
    m_selectionDescriptionLabel.setFont(font);
    m_selectionDescription.setReadOnly(true);
    m_selectionDescription.setFrameStyle(QFrame::NoFrame);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(&m_openTaskButton, 0, Qt::AlignRight);
    buttonLayout->addStretch();
    m_openTaskButton.setText(tr("Open"));
    m_selectionDescription.setHidden(true);
    m_openTaskButton.setHidden(true);
    //m_selectionDescriptionLabel.setHidden(true);
    QWidget *buttonLayoutWidget = new QWidget;
    buttonLayoutWidget->setLayout(buttonLayout);

    m_centerLayout.addWidget(&m_selectionDescriptionLabel, 0, Qt::AlignCenter | Qt::AlignTop);
    m_centerLayout.addWidget(&m_selectionDescription);
    m_centerLayout.addStretch();
    m_centerLayout.addWidget(buttonLayoutWidget, 0, Qt::AlignRight);
}

void CNewTab::setupRightLayout()
{
    QFont font;
    font.setPointSize(14);

    m_loadTaskTitle.setText(tr("Load task from file"));
    m_loadTaskTitle.setFont(font);

    m_loadTaskButton.setText(tr("Add new task"));

    m_rightLayout.addWidget(&m_loadTaskTitle, 0, Qt::AlignCenter | Qt::AlignTop);
    m_rightLayout.addWidget(&m_loadTaskButton);
    m_rightLayout.addStretch();
}

void CNewTab::treeViewItemSelected()
{
    QModelIndex currentSelection = m_view->selectionModel()->currentIndex();
    QString data = currentSelection.data(Qt::WhatsThisRole).toString();
    if (!data.isEmpty()) {
        m_selectionDescription.setHidden(false);
        m_openTaskButton.setHidden(false);
        //m_selectionDescriptionLabel.setHidden(false);
        m_selectionDescription.setText(data);
    } else {
        m_selectionDescription.setHidden(true);
        m_openTaskButton.setHidden(true);
        //m_selectionDescriptionLabel.setHidden(true);
    }
}

void CNewTab::onOpenTaskClicked()
{
    QModelIndex currentSelection = m_view->selectionModel()->currentIndex();
    QString name = currentSelection.data(Qt::DisplayRole).toString();

    if(name == tr("2D Movement")) {
        openTask(Tasks::MOVEMENT2D);
    } else if (name == tr("Hamming Code")) {
        openTask(Tasks::HAMMING);
    } else if (name == tr("Linear Independence")){
        openTask(Tasks::INDEPENDENCE);
    } else {
        qDebug() << "Task name not handled yet";
    }
}

void CNewTab::onLoadTaskClicked()
{
    QFileDialog::getOpenFileName(this, tr("Open local task"));
}
