#ifndef MAINPLUGINS_H
#define MAINPLUGINS_H

#include <QString>
#include <QObject>
#include <QImage>
class MainInterface
{
public:
    virtual ~MainInterface(){}
    virtual QString name() =0;
    virtual QString information() =0;
    virtual int Init(QString path)= 0;
    virtual QString execute(QImage image) =0;
    virtual QWidget* getSettingPanel(QWidget* parent = nullptr) = 0;//算法面板



};
Q_DECLARE_INTERFACE(MainInterface,
                    "org.qter.Examples.myplugin.MainInterface3")

#endif // MAINPLUGINS_H
