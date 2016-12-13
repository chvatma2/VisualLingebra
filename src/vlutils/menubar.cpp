#include "menubar.h"
#include "optionsdialog.h"

CMenuBar::CMenuBar(QWidget *parent) : QMenuBar(parent)
{
    m_file.setTitle(tr("File"));
    m_tools.setTitle(tr("Tools"));
    m_help.setTitle(tr("Help"));
    addMenu(&m_file);
    addMenu(&m_tools);
    addMenu(&m_help);

    m_newAssignement.setText(tr("New assignement"));
    m_exit.setText(tr("Exit"));
    m_about.setText(tr("About"));
    m_options.setText(tr("Options"));
    m_closeCurrent.setText(tr("Close current tab"));

    m_file.addAction(&m_newAssignement);
    m_file.addAction(&m_closeCurrent);
    m_file.addSeparator();
    m_file.addAction(&m_exit);

    m_tools.addAction(&m_options);

    m_help.addAction(&m_about);

    connect(&m_newAssignement, &QAction::triggered, this, &CMenuBar::newTaskClicked);
    connect(&m_closeCurrent, &QAction::triggered, this, &CMenuBar::closeCurrentClicked);
    connect(&m_options, &QAction::triggered, this, &CMenuBar::onOptionsClicked);
}

void CMenuBar::onOptionsClicked()
{
    COptionsDialog dlg;
    dlg.exec();
}
