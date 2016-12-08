#include "taskwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFile>

CTaskWidget::CTaskWidget(QWidget *parent) : QTabWidget(parent)
{
    //QHBoxLayout *mainLayout = new QHBoxLayout;

    //QFile input("../plugins/test.html");
    //input.open(QIODevice::ReadOnly);

    //m_page.setHtml(input.readAll());
    //m_page.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
    //mainLayout->addWidget(&m_page);

    //QVBoxLayout *indexLayout = new QVBoxLayout;
    //indexLayout->addWidget(new QLabel("Index"));
    //indexLayout->addWidget(&m_index);

    //mainLayout->addLayout(indexLayout);

    setAssignementWidget();
    setImplementationWidget();
    setOutputWidget();

    addTab(m_assignement, QIcon(), tr("Assignement"));
    addTab(m_implementation, QIcon(), tr("Implementation"));
    addTab(m_output, QIcon(), tr("Output"));

    setTabPosition(TabPosition::South);
}

void CTaskWidget::setAssignementWidget()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;

    QFile input("../plugins/test.html");
    input.open(QIODevice::ReadOnly);

    m_assignement = new QWidget;
    m_page.setHtml(input.readAll());
    m_page.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
    mainLayout->addWidget(&m_page);

    QVBoxLayout *indexLayout = new QVBoxLayout;
    indexLayout->addWidget(new QLabel("Index"));
    indexLayout->addWidget(&m_index);

    mainLayout->addLayout(indexLayout);
    m_assignement->setLayout(mainLayout);
}

void CTaskWidget::setImplementationWidget()
{
    m_implementation = new QWidget;

    QHBoxLayout *mainLayout = new QHBoxLayout;

    QVBoxLayout *inputsLayout = new QVBoxLayout;
    QVBoxLayout *uploadSolutionLayout = new QVBoxLayout;

    uploadSolutionLayout->addWidget(new QLabel(tr("Solution")));


    mainLayout->addLayout(uploadSolutionLayout);
    mainLayout->addLayout(inputsLayout);

    m_implementation->setLayout(mainLayout);
}

void CTaskWidget::setOutputWidget()
{
    m_output = new QWidget;

}
