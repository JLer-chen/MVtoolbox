#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userlistwidgets.h"
#include "usergraphicsview.h"
#include "userlwidgetsitem.h"
#include "imageproducer.h"
#include "imageconsumer.h"
#include "pluginmanagerview.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitUi();
    void InitsqliteBase();
    //在缩略图窗口点击按钮图片会显示在view
    void setShowImage();

    //void setAlgorithmTree();
    //get the path saves images,这个图片本地路径信息应该不是这个类来维护的，
    //是listimage类维护，而main类的成员变量有listimage对象，所以可以获取到这个信息
    //QString getImagePath();
    void slotLoopRun(bool checked);
    void camera_setting();
private slots:
    void on_once_action_triggered();
    void setReadFiles();
    //void on_once_action_changed();

    //void on_loop_action_triggered();

private:
    Ui::MainWindow *ui;
    UserListWidgets *listImage;//缩略图
    UserGraphicsView *window;//视图
    imageProducer *producer;//生产者，读图进队列
    imageConsumer *consumer;//消费者，处理图像

    QString pluginPath;//插件路径
    QString storePath;//图片处理后的存储路径
    pluginManagerView *managerView;
};

#endif // MAINWINDOW_H
