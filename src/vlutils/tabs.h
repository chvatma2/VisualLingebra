#ifndef ITABS_H
#define ITABS_H

#include <QWidget>

class ITabs : public QWidget
{
    Q_OBJECT
public:
    explicit ITabs(QWidget *parent = 0);
    ~ITabs();
    void setName(const QString &name);
    QString getName();
    virtual void retranslateUi() {}

private:
    QString m_name;

signals:

public slots:
};

#endif // ITABS_H
