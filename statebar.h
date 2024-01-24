#ifndef STATEBAR_H
#define STATEBAR_H

#include <QObject>
//算法占用资源相关，有多种状态
class stateBar : public QObject
{
    Q_OBJECT
public:
    enum AlgoState{
        INITIAL = 0x1,
        ONCEPROCESS= 0x2,
        LOOPPROCESS = 0x3,
        END = 0x4
    };
public:
    explicit stateBar(QObject *parent = nullptr);
    int getInfo();
    void setInfo(AlgoState );
signals:

public slots:
private:
    AlgoState info = INITIAL;
};

#endif // STATEBAR_H
