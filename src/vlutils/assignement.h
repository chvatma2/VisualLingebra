#ifndef CASSIGNEMENT_H
#define CASSIGNEMENT_H

#include <QString>

class CAssignement
{
public:
    CAssignement();

    void setDescritption(const QString &description);
    QString getDescription();

private:
    QString m_description;
};

#endif // CASSIGNEMENT_H
