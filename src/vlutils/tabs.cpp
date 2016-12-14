#include "tabs.h"

ITabs::ITabs(QWidget *parent) : QWidget(parent)
{

}

ITabs::~ITabs()
{

}

void ITabs::setName(const QString &name)
{
    m_name = name;
}

QString ITabs::getName()
{
    return m_name;
}
