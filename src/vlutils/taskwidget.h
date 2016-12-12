#ifndef CTASKWIDGET_H
#define CTASKWIDGET_H

#include <QWidget>
#include <QWebEngineView>
#include <QTreeView>
#include <QStatusBar>
#include <QTabWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QFrame>

class CTaskWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit CTaskWidget(QWidget *parent = 0);

signals:

public slots:
private:
    void setAssignementWidget();
    void setImplementationWidget();
    void setOutputWidget();

    QWebEngineView m_page;
    QTreeView m_index;
    QStatusBar m_statusBar;
    QTabWidget m_bottomTabs;
    QWidget *m_assignement = nullptr;
    QWidget *m_implementation = nullptr;
    QWidget *m_output = nullptr;
    QLineEdit m_uploadSolutionLineEdit;
    QTextEdit m_console;
    QHBoxLayout m_outputLayout;
    QScrollArea m_toolboxArea;
    QFrame m_minimizedToolbox;

private slots:
    void onUploadSolutionClicked();
    void onCompileSolutionClicked();
    void onHideButtonClicked();
    void onHideAnimationFinished();
    void onShowButtonClicked();
    void onShowAnimationFinished();

};

#endif // CTASKWIDGET_H
