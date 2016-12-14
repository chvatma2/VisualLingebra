#ifndef CMENUBAR_H
#define CMENUBAR_H

#include <QMenuBar>
#include <QAction>

class CMenuBar : public QMenuBar
{
    Q_OBJECT
public:
    CMenuBar(QWidget *parent = 0);
    void setLanguageList(QStringList list);
    void retranslateUi();
private:

    QMenu m_tools;
    QMenu m_help;
    QMenu m_file;
    QAction m_newAssignement;
    QAction m_exit;
    QAction m_options;
    QAction m_closeCurrent;
    QAction m_about;
    QStringList m_languages;

signals:
    void newTaskClicked();
    void closeCurrentClicked();
    void languageChanged(const QString &language);

private slots:
    void onOptionsClicked();
};

#endif // CMENUBAR_H
