#include "assignement.h"

CAssignement::CAssignement()
{

}

void CAssignement::setDescritption(const QString &description)
{
    m_description = description;
}

QString CAssignement::getDescription()
{
    return m_description;
}
