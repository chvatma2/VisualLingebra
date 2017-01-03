#include "menubar.h"
#include "optionsdialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QShortcut>
#include <QCoreApplication>

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
    m_saveTab.setEnabled(false);

    m_tools.addAction(&m_options);

    m_help.addAction(&m_about);

    //QShortcut *newShortcut = new QShortcut(QKeySequence("Ctrl+N"), this);
    //connect(newShortcut, &QShortcut::activated, &m_newAssignement, &QAction::trigger);

    //QShortcut *quitShortcut = new QShortcut(QKeySequence("Ctrl+Q"), this);
    //connect(quitShortcut, &QShortcut::activated, &m_exit, &QAction::trigger);

    //QShortcut *saveShortcut = new QShortcut(QKeySequence("Ctrl+S"), this);
    //connect(saveShortcut, &QShortcut::activated, &m_saveTab, &QAction::trigger);

    m_saveTab.setShortcut(QKeySequence::Save);
    m_exit.setShortcut(QKeySequence::Quit);
    m_newAssignement.setShortcut(QKeySequence::New);

    connect(&m_newAssignement, &QAction::triggered, this, &CMenuBar::newTaskClicked);
    connect(&m_closeCurrent, &QAction::triggered, this, &CMenuBar::closeCurrentClicked);
    connect(&m_options, &QAction::triggered, this, &CMenuBar::onOptionsClicked);
    connect(&m_saveTab, &QAction::triggered, this, &CMenuBar::onSaveTabClicked);
    connect(&m_exit, &QAction::triggered, QCoreApplication::instance(), &QCoreApplication::quit);
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
    m_newAssignement.setText(tr("New"));
    m_exit.setText(tr("Exit"));
    m_about.setText(tr("About"));
    m_options.setText(tr("Options"));
    m_closeCurrent.setText(tr("Close current tab"));
    m_saveTab.setText(tr("&Save current tab"));
}

void CMenuBar::enableSave(bool enable)
{
    m_saveTab.setEnabled(enable);
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
    if(!filename.isEmpty()) {
        msg.setText(tr("Tab successfully saved in file") + " " + filename);
        msg.exec();
    }
}
