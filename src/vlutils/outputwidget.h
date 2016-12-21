#ifndef COUTPUTWIDGET_H
#define COUTPUTWIDGET_H

#include <QWidget>

class COutputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit COutputWidget(QWidget *parent = 0);
    void retranslateUi();

signals:

public slots:
};

#endif // COUTPUTWIDGET_H
