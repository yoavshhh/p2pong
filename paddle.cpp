#include "paddle.h"

#include <QKeyEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

Paddle::Paddle(int x, int y, int width, int height)
    : QGraphicsItem(nullptr)
    , m_position(x, y)
    , m_size(width, height)
{
    setPos(x, y);
    setFlags(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

QRectF Paddle::boundingRect() const
{
    return QRectF(QPointF(0, 0), m_size);
}

void Paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
    painter->fillRect(boundingRect(), Qt::white);
}

void Paddle::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        qInfo("Left arrow paddle PRESSED");
        setPos(pos() + QPoint(-10, 0));
        return;
    case Qt::Key_Right:
        qInfo("Right arrow paddle PRESSED");
        setPos(pos() + QPoint(10, 0));
        return;
    default:
        event->ignore();
        return;
    }
}

void Paddle::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        qInfo("Left arrow paddle RELEASED");
        return;
    case Qt::Key_Right:
        qInfo("Right arrow paddle RELEASED");
        return;
    default:
        qInfo() << "Received: " << event->key() << "\n";
        event->ignore();
        return;
    }
}

void Paddle::focusInEvent(QFocusEvent *event)
{
    qInfo("CRAZY");
}

void Paddle::focusOutEvent(QFocusEvent *event)
{
    qInfo("CRAZIER");
}
