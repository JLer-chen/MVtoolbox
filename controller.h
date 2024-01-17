#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include "worker.h"
class Controller : public QObject
{
    Q_OBJECT
    QThread workThread;
public:
    Controller();
    ~Controller();

public slots:
    void handleResult();
signals:
    void operate();
};



#endif // CONTROLLER_H
