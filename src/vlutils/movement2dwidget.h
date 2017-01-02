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
    QPointF offset() {return m_offset;}
    QPointF direction() {return m_direction;}
    int rotation() {return m_rotation;}
    void setOffset(QPointF offset) {m_offset = offset;}
    void setDirection(QPointF direction) {m_direction = direction;}
    void setRotation(int rotation) {m_rotation = rotation;}
    void reset();

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *event) Q_DECL_OVERRIDE;


private:
    void processInput();

    QTransform m_transformation;
    QSet<int> m_pressedKeys;
    QTimer m_paintTimer;
    int m_rotation = 0;
    float m_speed = 6.0;
    QPointF m_direction;
    QPointF m_offset;
    QImage *m_car;
    float m_scaleFactor = 0.5;

signals:
    void upPressed(bool isPressed);
    void downPressed(bool isPressed);
    void leftPressed(bool isPressed);
    void rightPressed(bool isPressed);
    void keyChanged(QKeyEvent *event, bool state);

public slots:
    void update();
    void onKeyChanged(QKeyEvent *event, bool state);
    void onUpPressed();
    void onDownPressed();
    void onLeftPressed();
    void onRightPressed();
    void onUpReleased();
    void onDownReleased();
    void onLeftReleased();
    void onRightReleased();


};

#endif // CMOVEMENT2DWIDGET_H
