#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsItem>

class Paddle : public QGraphicsItem
{
public:
    Paddle(int x, int y, int width, int height);

    void grab();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;


private:
    QPointF m_position;
    QPointF m_size;
};

#endif // PADDLE_H
