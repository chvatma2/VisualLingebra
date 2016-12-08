#ifndef CTASKWIDGET_H
#define CTASKWIDGET_H

#include <QWidget>
#include <QWebEngineView>
#include <QTreeView>
#include <QStatusBar>
#include <QTabWidget>

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

private slots:

};

#endif // CTASKWIDGET_H
