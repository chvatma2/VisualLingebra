#include "menubar.h"
#include "optionsdialog.h"

#include <QFileDialog>
#include <QMessageBox>

CMenuBar::CMenuBar(QWidget *parent) : QMenuBar(parent)
{

    addMenu(&m_file);
    addMenu(&m_tools);
    addMenu(&m_help);

    retranslateUi();

    m_file.addAction(&m_newAssignement);
    m_file.addAction(&m_closeCurrent);
    m_file.addAction(&m_saveTab);
    m_file.addSeparator();
    m_file.addAction(&m_exit);

    m_tools.addAction(&m_options);

    m_help.addAction(&m_about);

    connect(&m_newAssignement, &QAction::triggered, this, &CMenuBar::newTaskClicked);
    connect(&m_closeCurrent, &QAction::triggered, this, &CMenuBar::closeCurrentClicked);
    connect(&m_options, &QAction::triggered, this, &CMenuBar::onOptionsClicked);
    connect(&m_saveTab, &QAction::triggered, this, &CMenuBar::onSaveTabClicked);
}

void CMenuBar::setLanguageList(QStringList list)
{
    m_languages = list;
}

void CMenuBar::retranslateUi()
{
    m_file.setTitle(tr("File"));
    m_tools.setTitle(tr("Tools"));
    m_help.setTitle(tr("Help"));
    m_newAssignement.setText(tr("New assignement"));
    m_exit.setText(tr("Exit"));
    m_about.setText(tr("About"));
    m_options.setText(tr("Options"));
    m_closeCurrent.setText(tr("Close current tab"));
    m_saveTab.setText(tr("Save current tab"));
}

void CMenuBar::onOptionsClicked()
{
    COptionsDialog dlg(m_languages);
    connect(&dlg, &COptionsDialog::languageChanged, this, &CMenuBar::languageChanged);
    dlg.exec();
}

void CMenuBar::onSaveTabClicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save current tab"));
    QMessageBox msg;
    msg.setText(tr("Tab successfully saved in file") + " " + filename);
    msg.exec();
}
