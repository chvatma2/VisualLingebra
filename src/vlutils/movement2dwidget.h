#ifndef CMOVEMENT2DWIDGET_H
#define CMOVEMENT2DWIDGET_H

#include <QWidget>
#include <QSet>

class CMovement2DWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CMovement2DWidget(QWidget *parent = 0);

private:
    QSet<int> m_pressedKeys;
signals:

public slots:
};

#endif // CMOVEMENT2DWIDGET_H
