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

    //statusBarLayout->addLayout(mainLayout);

    //statusBarLayout->addWidget(&m_statusBar);
    //setLayout(statusBarLayout);

    //m_assignement.setDown(true);
    addTab(new QWidget(), QIcon(), tr("Assignement"));
    addTab(new QWidget(), QIcon(), tr("Implementation"));
    addTab(new QWidget(), QIcon(), tr("Output"));

    setTabPosition(TabPosition::South);
}
