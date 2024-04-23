#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QVector2D>

class Ball : public QGraphicsItem
{
public:
    Ball(qreal radius, qreal speed, qreal dirX, qreal dirY);

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;
    void update(const QRectF &rect);

private:
    qreal mRadius;
    qreal mSpeed;
    QVector2D mDir;
};

#endif // BALL_H
