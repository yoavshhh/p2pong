#ifndef PONGVIEW_H
#define PONGVIEW_H

#include <QGraphicsView>

class PongView : public QGraphicsView
{
    Q_OBJECT
public:
    PongView();
    PongView(QWidget *parent = nullptr);

    // protected:
    //     void keyPressEvent(QKeyEvent *event) override;
    //     void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // PONGVIEW_H
