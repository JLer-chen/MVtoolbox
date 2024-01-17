#ifndef IMAGECONSUMER_H
#define IMAGECONSUMER_H
#include <QWaitCondition>
#include "imageproducer.h"
#include <QThread>
#include "mainplugins.h"


class imageConsumer : public QThread
{
    Q_OBJECT
private:
    imageProducer *p;
    bool run_State = false;
public:
    explicit imageConsumer();
    ~imageConsumer();
    //~imageConsumer() override;
    void start_Thread();
    void setProducer(imageProducer* p_);
    void consumOneImage();
protected:
    void run() override;
signals:
    void callPluginByOne(QImage image);
    void callPluginByThread(QImage image);
};

#endif // IMAGECONSUMER_H
