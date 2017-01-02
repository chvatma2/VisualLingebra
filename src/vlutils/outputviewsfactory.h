#ifndef COUTPUTVIEWSFACTORY_H
#define COUTPUTVIEWSFACTORY_H

#include <QString>
#include <QObject>

class QWidget;

struct TaskWidgets {
    QWidget* referenceWidget;
    QWidget* studentWidget;
    QWidget* controlPanel;
};

class COutputViewsFactory : public QObject
{
    Q_OBJECT
public:
    COutputViewsFactory(QObject *parent = Q_NULLPTR);
    static TaskWidgets loadWidgetsFromPlugin(const QString &pluginpath);
};

#endif // COUTPUTVIEWSFACTORY_H
