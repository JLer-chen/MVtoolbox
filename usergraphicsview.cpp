#include "usergraphicsview.h"
#include <QGraphicsRectItem>
#include <QWheelEvent>
#include <QDebug>
UserGraphicsView::UserGraphicsView( )
{
    scene  = new QGraphicsScene;
    scene->setBackgroundBrush(QBrush(QPixmap(":/images/board.png")));
    scene->setSceneRect(-500,-500,2000,2000);
    qDebug()<<"before setScene"<<endl;
    m_window = new Myview();
    m_window->setScene(scene);
    qDebug()<<"after setScene"<<endl;
    m_window->setAlignment(Qt::AlignCenter);

    QGraphicsRectItem *rect = new QGraphicsRectItem(0,0,30,30);
    rect->setBrush(Qt::blue);
    scene->addItem(rect);

}

Myview *UserGraphicsView::getWindow()
{
    return m_window;
}

void UserGraphicsView::showImage(QString path)
{
    scene->removeItem(tempItem);
    QPixmap selectImage(path);
     tempItem = new UserImageItem(selectImage);
    scene->addItem(tempItem);
}

