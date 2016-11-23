#include "newtab.h"

#include <QHBoxLayout>
#include <QLabel>

CNewTab::CNewTab(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(new QLabel("TEST LEFT"));
    layout->addWidget(new QLabel("TEST CENTER"));
    layout->addWidget(new QLabel("TEST RIGHT"));
}
