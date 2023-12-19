#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
class Myview : public QGraphicsView
{
public:
    Myview( QWidget *parent = nullptr);
    void Translate(QPointF delta);

protected:
    virtual void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool m_isPush = false;
    QPointF m_lastMousePos;
};

#endif // MYVIEW_H
