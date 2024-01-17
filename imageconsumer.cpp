#include "imageconsumer.h"
#include <QMutexLocker>
#include <QImage>
#include <QDir>
#include <QPluginLoader>
#include <QDebug>
#include <QStringList>
#include <QTime>
extern const int queue_size;//图像队列的长度
extern QWaitCondition bufferNotEmpty1;
extern QWaitCondition bufferNotFull1;
extern QMutex thread_mutex1;


imageConsumer::imageConsumer()
{

}

imageConsumer::~imageConsumer()
{

}



void imageConsumer::start_Thread()
{
    run_State = true;
    this->start();

}

void imageConsumer::setProducer(imageProducer *p_)
{
    p = p_;
}

void imageConsumer::run()
{
    while(run_State){
        QMutexLocker locker(&thread_mutex1);
         qDebug()<<"consumer get the mutex"<<endl;
        if(p->isEmpty()){
            qDebug()<<"queue is empty";
            bufferNotEmpty1.wait(&thread_mutex1);
        }
        int before = QTime::currentTime().msecsSinceStartOfDay();
        QImage curImage = p->imageBuffer.dequeue();

        bufferNotFull1.wakeAll();
        locker.unlock();
        qDebug()<<"before emit";
        emit callPluginByThread(curImage);
        qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
               <<"callPlugin 耗时："<<QTime::currentTime().msecsSinceStartOfDay() - before;
        qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
               <<"curTime:"<<QTime::currentTime().toString("hh:mm:ss.zzz");
    }
    this->exec();
}

void imageConsumer::consumOneImage()
{
    if(p->imageBuffer.size()==0){
        qDebug()<<"imageBuffer.size:"<<p->imageBuffer.size()<<endl;
        return ;
}
    //从队列获取图像
    QImage curImage = p->imageBuffer.dequeue();

    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"before callPlugin";
        //调用插件处理图像
    emit callPluginByOne(curImage);
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"after callPlugin";

}
