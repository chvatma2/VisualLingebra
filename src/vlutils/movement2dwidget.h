#ifndef CMOVEMENT2DWIDGET_H
#define CMOVEMENT2DWIDGET_H

#include <QWidget>
#include <QSet>
#include <QTimer>
#include <QTransform>

class CMovement2DWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CMovement2DWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;


private:
    void processInput();

    QTransform m_transformation;
    QSet<int> m_pressedKeys;
    QTimer m_paintTimer;
    int m_rotation;
    float m_speed = 6.0;
    QPointF m_direction;
    QPointF m_offset;
    QImage *m_car;
    float m_scaleFactor = 0.5;

signals:

public slots:
    void update();
};

#endif // CMOVEMENT2DWIDGET_H
