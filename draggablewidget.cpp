#include "draggablewidget.h"

DraggableWidget::DraggableWidget(QWidget *parent)
    : QWidget(parent), topParent(parentWidget()), dragging(false)
{
    setMouseTracking(true); // Enable mouse tracking to receive mouse move events
    while (topParent->parentWidget()) {
        topParent = topParent->parentWidget();
    }
}

void DraggableWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        // Record the position where the mouse was pressed relative to the widget's position
        m_dragStartPos = event->globalPosition() - topParent->pos();
        dragging = true;
        event->accept();
    }
}

void DraggableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dragging)
    {
        // Calculate the new position of the widget based on the mouse movement
        topParent->move((event->globalPosition() - m_dragStartPos).toPoint());
        event->accept();
    }
}

void DraggableWidget::mouseReleaseEvent(QMouseEvent *event)
{
    dragging = false;
}
