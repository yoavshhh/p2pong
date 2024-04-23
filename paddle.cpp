#include "paddle.h"

#include <QKeyEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

Paddle::Paddle(int x, int y, int width, int height) :
    m_position(x, y), m_size(width, height)
{
}

void Paddle::grab()
{
    grabKeyboard();
    setFocus();
}

QRectF Paddle::boundingRect() const
{
    return QRectF(m_position, m_size);
}

void Paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
    painter->fillRect(boundingRect(), Qt::white);
}

void Paddle::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::LeftArrow:
        qInfo("Left arrow paddle PRESSED");
        m_position.setX(std::fmax(m_position.x() - 5, 0));
        return;
    case Qt::RightArrow:
        qInfo("Right arrow paddle PRESSED");
        m_position.setX(std::fmin(m_position.x() + 5, sceneBoundingRect().right()));
        return;
    default:
        event->ignore();
        return;
    }
}

void Paddle::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::LeftArrow:
        qInfo("Left arrow paddle RELEASED");
        return;
    case Qt::RightArrow:
        qInfo("Right arrow paddle RELEASED");
        return;
    default:
        event->ignore();
        return;
    }
}
