#include "menubar.h"

CMenuBar::CMenuBar(QWidget *parent) : QMenuBar(parent)
{
    m_file.setTitle(tr("File"));
    m_tools.setTitle(tr("Tools"));
    m_help.setTitle(tr("Help"));
    addMenu(&m_file);
    addMenu(&m_tools);
    addMenu(&m_help);
}
