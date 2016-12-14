#include "movement2dwidget.h"

#include <QPainter>
#include <QKeyEvent>

CMovement2DWidget::CMovement2DWidget(QWidget *parent) : QWidget(parent)
{
    m_paintTimer.setSingleShot(false);
    m_paintTimer.start(16);
    setFocusPolicy(Qt::StrongFocus);

    m_car = new QImage("../assets/car.png");

    connect(&m_paintTimer, &QTimer::timeout, this, &CMovement2DWidget::update);
    m_offset.setX(100);
    m_offset.setY(100);

}

void CMovement2DWidget::paintEvent(QPaintEvent *event)
{
    processInput();
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    QTransform transform;

    transform.translate(m_offset.x(), m_offset.y());
    transform.rotate(m_rotation);
    transform.scale(m_scaleFactor, m_scaleFactor);
    painter.setWorldMatrixEnabled(true);
    painter.setWorldTransform(transform);
    painter.drawImage(-m_car->width()/2, -m_car->height()/2, *m_car);

}

void CMovement2DWidget::keyPressEvent(QKeyEvent *event)
{
    m_pressedKeys.insert(event->key());
    switch(event->key()) {
    case Qt::Key_Up:
        emit upPressed(true);
        break;
    case Qt::Key_Down:
        emit downPressed(true);
        break;
    case Qt::Key_Left:
        emit leftPressed(true);
        break;
    case Qt::Key_Right:
        emit rightPressed(true);
        break;
    }
}

void CMovement2DWidget::keyReleaseEvent(QKeyEvent *event)
{
    m_pressedKeys.remove(event->key());
    switch(event->key()) {
    case Qt::Key_Up:
        emit upPressed(false);
        break;
    case Qt::Key_Down:
        emit downPressed(false);
        break;
    case Qt::Key_Left:
        emit leftPressed(false);
        break;
    case Qt::Key_Right:
        emit rightPressed(false);
        break;
    }
}

void CMovement2DWidget::processInput()
{
    if(m_pressedKeys.contains(Qt::Key_Left))
        m_rotation -= 1;
    if(m_pressedKeys.contains(Qt::Key_Right))
        m_rotation += 1;
    if(m_pressedKeys.contains(Qt::Key_Up))
        m_offset += m_speed * m_scaleFactor * m_direction;
    if(m_pressedKeys.contains(Qt::Key_Down))
        m_offset -= m_speed * m_scaleFactor * m_direction;

    QTransform rotation;
    m_rotation %= 360;
    rotation.rotate(m_rotation);
    m_direction = QPointF(1.0, 0.0) * rotation;

}

void CMovement2DWidget::update()
{
    QWidget::update();
}
