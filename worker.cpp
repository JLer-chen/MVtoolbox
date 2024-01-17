#include "worker.h"
#include "mainwindow.h"
#include <QTime>
#include <QDebug>
#include <QMutex>
extern QMutex thread_mutex1;
Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::dowork(){
    qDebug()<<"before sleep";
    int before = QTime::currentTime().msecsSinceStartOfDay();
    thread_mutex1.lock();
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"等待上锁的时间："<<QTime::currentTime().msecsSinceStartOfDay() - before<<"ms";

    emit resultReady();
}
