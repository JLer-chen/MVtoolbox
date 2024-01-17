#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMutex>
#include <QFileDialog>
#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include <QTime>
#include "controller.h"
#include "mainwindow.h"
extern QMutex thread_mutex1;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化界面

    //查看数据库驱动
    //qDebug()<< "Database driver has： " << QSqlDatabase::drivers();
    //初始化数据库
    //InitsqliteBase();

    //生产者消费者线程初始化
    producer = new imageProducer();
    consumer = new imageConsumer();
    consumer->setProducer(producer);
    thread_mutex1.lock();
    producer->start_Thread();
    consumer->start_Thread();


    managerView = new pluginManagerView();


    InitUi();

    //信号和槽设置
    //缩略图按钮的信号和view界面的槽，用于在view中显示图像
    //在选中图片点击确定后才发出enableConnect信号
    connect(listImage,&UserListWidgets::enableConnect,this,&MainWindow::setShowImage);
    connect(listImage,&UserListWidgets::enableConnect,this,&MainWindow::setReadFiles);



    //consumer call the plugin
    connect(ui->camera_action,&QAction::triggered,this,&MainWindow::camera_setting);
    connect(consumer,&imageConsumer::callPluginByOne,managerView,&pluginManagerView::process);
    connect(consumer,&imageConsumer::callPluginByThread,managerView,&pluginManagerView::process);

    connect(ui->loop_action,&QAction::triggered,this,&MainWindow::slotLoopRun);
    //算法插件处理完图像后emit to view
    connect(managerView,&pluginManagerView::sendDstImage,window,&UserGraphicsView::showDstImage);
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle(tr("note！"));
    QLabel* label = new QLabel(dialog);
    label->setText(tr("please firstly confirm the camera setting on the top left corner."));
    label->resize(800,50);
    dialog->show();
    qDebug()<<"cur working dire:"<<QDir::currentPath();
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"curTime:"<<QTime::currentTime().toString("hh:mm:ss.zzz");
}


/**
 * @brief MainWindow::InitUi
 */
void MainWindow:: InitUi(){
    listImage = new UserListWidgets();
    ui->gridLayout_8->addWidget(listImage);

    window = new UserGraphicsView();
    ui->gridLayout_9->addWidget(window->getWindow());
//主界面加载插件管理器
    ui->gridLayout_2->addWidget(managerView);
    if(!managerView->loadPlugins("../../plugins")){
        qDebug()<<"no plugin could load!";
        return ;
    }
    managerView->setAlgorithmTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitsqliteBase()
{
//    //数据库创建
    QSqlDatabase config_database;
    config_database = QSqlDatabase::addDatabase("QMYSQL");
    config_database.setHostName("127.0.0.1");
    config_database.setUserName("root");
    config_database.setPassword("131735qq2");
    config_database.setDatabaseName("qt_test");  //数据库名

//    //打开数据库
    if(config_database.open()==false)
    {
        qDebug()<<"open fail"<<endl;
        return;
    }

//    //连接数据库并进行增删改查
    QSqlQuery query(config_database); //与打开的数据库相连

    //创建一个表
    if(!query.exec("create table config_table (id int primary key, name varchar(30), path varchar(50) )"))
    {
        qDebug() << "Error: Fail to create table." <<config_database.lastError()<<endl;
    }
    else
    {
        qDebug() << "Table created!";
    }
    if(!query.exec("SELECT * FROM qt_test")){
        qDebug()<<"Error: Fail to open table."<<config_database.lastError()<<endl;
    }

          while (query.next()) {
              QString name = query.value(1).toString();
              int age = query.value(2).toInt();
              qDebug() << name << age;
          }


//    //表中插入数据
    query.exec("insert into config_table (id, name, path) VALUES (1, 'Camera', 'C:/Users/Administrator/Desktop')");
    config_database.close();
}

void MainWindow::setShowImage()
{
    qDebug()<<"缩略图的个数："<<listImage->getNumberofItem()<<endl;
    for(int i=0;i<listImage->getNumberofItem();i++){
        connect(listImage->getItem(i),&UserLWidgetsItem::sendPath,window,&UserGraphicsView::showImage);
    }
}



void MainWindow::camera_setting()
{
    storePath = QFileDialog::getExistingDirectory();
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<storePath;
    managerView->initPlugins(storePath);

}




/**
 * @brief MainWindow::on_once_action_triggered
 *
 */
void MainWindow::on_once_action_triggered()
{
    qDebug()<<"before prouceOneImage()"<<endl;
    if(!producer->produceOneImage()){
        return ;
    };
    qDebug()<<"before consumOneImage"<<endl;
    consumer->consumOneImage();
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"after consumeOneImage";

}
/**
 * @brief MainWindow::setReadFiles
 * 当listImage确定所选择的图片后，producer对象需要更新图片以及指针
 */
void MainWindow::setReadFiles()
{
    //send arguments to producer,include path of images(直接传容器得了，
    //这样producer类就不需要额外处理了)
    producer->setReadList(listImage->getImageList());

}

void MainWindow::slotLoopRun(bool checked)
{
    if(checked){
        qDebug()<<"store:"<<storePath.isEmpty();
        if( storePath.isEmpty() ){
            QMessageBox::information(this,"imformation",tr("请设置存储路径"));
            return;
        }
        ui->once_action->setEnabled(false);
        ui->loop_action->setIcon(QIcon(":/images/orange_loop.png"));
        //此时无法进行算法选择,code待补充



        thread_mutex1.unlock();
    }else {
        qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
               <<"enter checked is false";
        ui->once_action->setEnabled(true);
        ui->loop_action->setIcon(QIcon(":/images/blue_loop.png"));
//        qDebug()<<"before sleep";
//        int before = QTime::currentTime().msecsSinceStartOfDay();
//        QThread::sleep(10);
//        qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
//               <<"sleep的时间："<<QTime::currentTime().msecsSinceStartOfDay() - before<<"ms";
        //如果有其他线程已经占用这个锁，则等他释放后再次上锁
//        Controller controller ;
//        emit controller.operate();
        qDebug()<<"before sleep";
        int before = QTime::currentTime().msecsSinceStartOfDay();
        thread_mutex1.lock();
        qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
               <<"等待上锁的时间："<<QTime::currentTime().msecsSinceStartOfDay() - before<<"ms";
        qDebug()<<"end the loop";
}

}




