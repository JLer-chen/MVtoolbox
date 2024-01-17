#include "imageproducer.h"
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QImage>
#include <QDebug>
#include <QWidget>
#include <QLabel>
#include <QTime>
const int queue_size = 10;//图像队列的长度

QWaitCondition bufferNotEmpty1;
QWaitCondition bufferNotFull1;
QMutex thread_mutex1;
imageProducer::imageProducer()
{

}

imageProducer::~imageProducer()
{

}

void imageProducer::start_Thread()
{
    run_State = true;
    this->start();

}

void imageProducer::run()
{
    while(run_State){
        QMutexLocker locker(&thread_mutex1);
        qDebug()<<"producer get the mutex"<<endl;
        if(this->isFull()){
            bufferNotFull1.wait(&thread_mutex1);
        }
        if(curPoint >= readImageList.size()){
            //等待更新readlist
            msleep(1000);
            qDebug()<<"producer already deal all image,please update readlistImage!";
            continue ;
        }
        int before = QTime::currentTime().msecsSinceStartOfDay();
        imageBuffer.enqueue(QImage(readImageList.at(curPoint)));
        curPoint++;
        qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
               <<"image into queue 耗时："<<QTime::currentTime().msecsSinceStartOfDay() - before;
        bufferNotEmpty1.wakeAll();
        locker.unlock();
    }
    this->exec();
}

bool imageProducer::produceOneImage()
{
    //QTime time;
    int before = QTime::currentTime().msecsSinceStartOfDay();

    //从容器中读取内容时需要判断下标是否合法
    if(curPoint == readImageList.size()){
        qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
               <<"图片已全部读取";
        QWidget* widget = new QWidget();
        QLabel* label =new QLabel(widget);
        label->setText(tr("图片已全部读取"));
        widget->show();
        return false;
    }
    QString curImage = readImageList.at(curPoint);
    //此处保险起见需要判断存储图像的队列是否满了，
    //但不用给队列上锁，因为同步操作由代码顺序控制。
    if(this->isFull()){
        qDebug()<<"queue is already fulled";
        return false;}

    imageBuffer.enqueue(QImage(curImage));
    curPoint++;
    timeByOne = QTime::currentTime().msecsSinceStartOfDay() - before;
    qDebug()<<"before:"<<before;
    qDebug()<<"timeByOne:"<<timeByOne;
    return true;
}
/**
 * @brief imageProducer::setReadList
 * @param imagelist
 * 凡是更新producer的读图路径，都需要重新设置指针
 */
void imageProducer::setReadList(const QStringList imagelist)
{
    readImageList = imagelist;
    curPoint = 0;
}

bool imageProducer::isFull()
{
    if(imageBuffer.size()<queue_size){
        return false;
    }
    return true;
}

bool imageProducer::isEmpty()
{
    if(imageBuffer.size()>0){
        return false;
    }
    return true;
}
