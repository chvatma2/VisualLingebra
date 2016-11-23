#ifndef CMENUBAR_H
#define CMENUBAR_H

#include <QMenuBar>

class CMenuBar : public QMenuBar
{
public:
    CMenuBar(QWidget *parent = 0);
private:
    QMenu m_tools;
    QMenu m_help;
    QMenu m_file;
};

#endif // CMENUBAR_H
