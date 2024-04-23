#ifndef DRAGGABLEWIDGET_H
#define DRAGGABLEWIDGET_H

#include <QWidget>
#include <QMouseEvent>

class DraggableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DraggableWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QWidget *topParent;
    bool dragging;
    QPointF m_dragStartPos;
};

#endif // DRAGGABLEWIDGET_H
