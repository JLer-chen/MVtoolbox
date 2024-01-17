#ifndef IMAGEPRODUCER_H
#define IMAGEPRODUCER_H
#include <QThread>
#include <QQueue>
#include <QImage>

class imageProducer : public QThread
{
    Q_OBJECT
public:
    QQueue<QImage> imageBuffer;
public:
    imageProducer();
    ~imageProducer();
    void start_Thread();
    void run() override;

    bool produceOneImage();
    void setReadList(const QStringList imageList);
    //判断图片队列是否为空、满
    bool isFull();
    bool isEmpty();
private:
    bool run_State = false;
    //从本地的路径下读取图片
    QStringList readImageList;
    //需要指针指向当前处理完的图片
    int curPoint = 0;
    //读取一张图片到队列需要的时间
    float timeByOne =0;

};


#endif // IMAGEPRODUCER_H
