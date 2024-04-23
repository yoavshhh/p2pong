#include "pongview.h"

#include <QGraphicsItem>
#include <QKeyEvent>

PongView::PongView() {}

PongView::PongView(QWidget *parent)
    : QGraphicsView(parent)
{}

// void PongView::keyPressEvent(QKeyEvent *event)
// {
//     // qInfo() << "recieved event: " << event->key() << "\n";
//     // event->ignore();
//     // qInfo() << "Focus child: " << scene()->focusItem() << "\n";
//     // for (QGraphicsItem *item : scene()->items()) {
//     //     qInfo() << "sending to child: " << item->type() << "\n";
//     //     if (event->isAccepted())
//     //         return;
//     // }
//     // QGraphicsView::keyPressEvent(event);
// }

// void PongView::keyReleaseEvent(QKeyEvent *event)
// {
// }
