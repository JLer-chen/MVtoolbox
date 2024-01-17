#include "controller.h"
#include <QDebug>
Controller::Controller()
{
    Worker* work = new Worker;
    work->moveToThread(&workThread);
    connect(&workThread,SIGNAL(finished()),work,SLOT(deleteLater()));
    connect(this,&Controller::operate,work,&Worker::dowork);
    connect(work,&Worker::resultReady,this,&Controller::handleResult);
    workThread.start();
    qDebug()<<"enter controller startTH";
}

Controller::~Controller(){
    qDebug()<<"before th wait";
    workThread.wait();
    qDebug()<<"after th wait";
}

void Controller::handleResult()
{
    qDebug()<<"handleResult";
}
