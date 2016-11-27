#ifndef CMENUBAR_H
#define CMENUBAR_H

#include <QMenuBar>
#include <QAction>

class CMenuBar : public QMenuBar
{
public:
    CMenuBar(QWidget *parent = 0);
private:
    QMenu m_tools;
    QMenu m_help;
    QMenu m_file;
    QAction m_newAssignement;
    QAction m_exit;
    QAction m_options;
    QAction m_about;
};

#endif // CMENUBAR_H
