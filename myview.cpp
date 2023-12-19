#include "myview.h"
#include <QWheelEvent>
#include <QGraphicsItem>
#include <QDebug>
Myview::Myview(QWidget *parent )
    :QGraphicsView(parent)
{

}

void Myview::Translate(QPointF delta)
{
    int w = viewport()->rect().width();
    int h = viewport()->rect().height();

    QPoint newCenter(int(w/2.0 - delta.x() + 0.5) ,int(h/2.0 - delta.y() + 0.5));

    this->centerOn(mapToScene(newCenter));
}

void Myview::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0){
        scale(1.2,1.2);
    }else {
        scale(1/1.2,1/1.2);
}
    QGraphicsView::wheelEvent(event);
}

void Myview::mousePressEvent(QMouseEvent *event)
{
    QGraphicsItem *item = itemAt(event->pos());
    qDebug()<<tr("before")<<endl;
//    if(item && (item->type() != QGraphicsPixmapItem::Type)){
//        QGraphicsView::mousePressEvent(event);
//        return ;
//    }
    qDebug()<<tr("fanhui")<<endl;
    if(event->button() == Qt::LeftButton){

        m_isPush = true;
        m_lastMousePos = event->pos();
    }
    QGraphicsView::mousePressEvent(event);
    qDebug()<<m_isPush<<endl;
}

void Myview::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isPush == false){
        QGraphicsView::mouseMoveEvent(event);
        return ;
    }

    QPointF delta = event->pos() - m_lastMousePos;
    Translate(delta);
    m_lastMousePos = event->pos();
    QGraphicsView::mouseMoveEvent(event);
    qDebug()<<m_lastMousePos.x()<<endl;
}

void Myview::mouseReleaseEvent(QMouseEvent *event)
{
    if(!m_isPush){
        QGraphicsView::mouseReleaseEvent(event);
        return ;
    }

    if(event->button() == Qt::LeftButton){
        m_isPush = false;
        //m_lastMousePos = event->pos();
    }
    QGraphicsView::mouseReleaseEvent(event);
    qDebug()<<m_isPush<<endl;
}
