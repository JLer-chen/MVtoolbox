#include "usergraphicsview.h"
#include <QGraphicsRectItem>
#include <QWheelEvent>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QTime>
UserGraphicsView::UserGraphicsView( )
{
    scene  = new QGraphicsScene;
    scene->setBackgroundBrush(QBrush(QPixmap(":/images/board.png")));
    scene->setSceneRect(-500,-500,3000,3000);
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
    QList<QGraphicsItem* > allItems = scene->items();
    if(!allItems.contains(tempItem)){
        QPixmap selectImage(path);
         tempItem = new UserImageItem(selectImage);
         scene->addItem(tempItem);
        return ;
    }
    scene->removeItem(tempItem);
    QPixmap selectImage(path);
     tempItem = new UserImageItem(selectImage);
     scene->addItem(tempItem);
}

bool UserGraphicsView::showDstImage(QString ImagePath)
{
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"enter the windows function ";
    scene->removeItem(tempItem);

    //这部分是io操作，从内存读图片，可能较为耗时
    int before = QTime::currentTime().msecsSinceStartOfDay();
    QImage Image(ImagePath);
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"io操作耗时："<<QTime::currentTime().msecsSinceStartOfDay()-before<<"ms";
    before  = QTime::currentTime().msecsSinceStartOfDay();
    QPixmap dstImage = QPixmap::fromImage(Image);
    tempItem = new UserImageItem(dstImage);
    scene->addItem(tempItem);
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"add image to scene耗时："<<QTime::currentTime().msecsSinceStartOfDay()-before<<"ms";
    return true;
}

