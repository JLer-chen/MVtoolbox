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
#include <QLineEdit>
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
    connect(consumer,&imageConsumer::callPluginByThread,managerView,&pluginManagerView::process,Qt::BlockingQueuedConnection);

    connect(ui->loop_action,&QAction::triggered,this,&MainWindow::slotLoopRun);
    //算法插件处理完图像后emit to view
    connect(managerView,&pluginManagerView::sendDstImage,window,&UserGraphicsView::showDstImage);

    QMessageBox::information(this,tr("重要提示！！！"),tr("请首先设置图像处理后的存储位置。"));
    qDebug()<<"cur working dire:"<<QDir::currentPath();
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"curTime:"<<QTime::currentTime().toString("hh:mm:ss.zzz");


    AlgoState = new stateBar();
    ui->statusBar->showMessage(tr("读图时间：- ，算法处理时间：-"),0);
    qDebug()<<AlgoState->getInfo();
    AlgoState->setInfo(stateBar::LOOPPROCESS);
    qDebug()<<AlgoState->getInfo();
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
    QMessageBox::information(this,"note",QDir::currentPath());
    // if(!managerView->loadPlugins("plugins")){
    //     qDebug()<<"no plugin could load!";
    //     return ;
    // }
    // managerView->setAlgorithmTree();

//相机界面创建
    camera = new camerasetting(this);
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


/**
 * @brief MainWindow::camera_setting
 * 相机设置：设置插件所在路径和处理后的图片所在路径
 */
void MainWindow::camera_setting()
{
    //原来的代码：待删除
    // storePath = QFileDialog::getExistingDirectory();
    // qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
    //        <<storePath;
    // managerView->initPlugins(storePath);

    //创建对话框，用户输入图片存储路径和插件路径
    // QDialog *dialog = new QDialog(this);
    // QGridLayout *layout = new QGridLayout();
    // QLabel *storePath = new QLabel(tr("请选择图像存储路径："));
    // QLabel *pluginPath = new QLabel(tr("请确定插件所在路径"));
    // QLineEdit *storePath_edit = new QLineEdit;
    // QLineEdit *pluginPath_edit = new QLineEdit;
    // QPushButton *storePath_button = new QPushButton;
    // QPushButton *pluginPath_button = new QPushButton;
    // storePath_button->setIcon(QIcon(":/images/orange_path.png"));

    // layout->addWidget(storePath,0,0,1,2);
    // layout->addWidget(storePath_edit,0,3,1,4);
    // layout->addWidget(storePath_button,0,8,1,1);
    // dialog->setLayout(layout);
    // dialog->show();

    //判断相机设置是否成功，若成功则主线程会读取插件并初始化插件
    if(camera->exec() == QDialog::Accepted){
        this->show();
        storePath = camera->get_storePath();
        pluginPath = camera->get_pluginPath();
        if(!managerView->loadPlugins(pluginPath)){
            qDebug()<<"no plugin could load!";
            return ;
        }
        managerView->setAlgorithmTree();
        managerView->initPlugins(storePath);
    }

}




/**
 * @brief MainWindow::on_once_action_triggered
 *
 */
void MainWindow::on_once_action_triggered()
{
    //获取插件管理器算法选择情况
    //用户友好型代码，没有选择算法时不能执行
    if(!managerView->isSelected()){
        QMessageBox::information(this,tr("错误"),tr("请先选择左侧栏的算法！"));
        return ;
    }
    qDebug()<<"before prouceOneImage()"<<endl;
    if(!producer->produceOneImage()){
        return ;
    };
    qDebug()<<"before consumOneImage"<<endl;
    consumer->consumOneImage();
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"after consumeOneImage";
    int readTime = producer->getTime();
    int processTime = managerView->getOnceTimer();
    ui->statusBar->showMessage("读图时间："+QString::number(readTime)+"ms 算法处理时间："+
                               QString::number(processTime)+"ms");

}
/**
 * @brief MainWindow::setReadFiles
 * 当listImage确定所选择的图片后，producer对象需要更新图片以及指针
 */
void MainWindow::setReadFiles()
{
    //send arguments to producer,include path of images(直接传容器得了，
    //这样producer类就不需要额外处理了)
    qDebug()<<"enter setRead";
    producer->setReadList(listImage->getImageList());

}

void MainWindow::slotLoopRun(bool checked)
{
    //获取插件管理器算法选择情况
    //用户友好型代码，没有选择算法时不能执行
    if(!managerView->isSelected()){
        QMessageBox::information(this,tr("错误"),tr("请先选择左侧栏的算法！"));
        return ;
    }
    //将算法占用资源栏置空，循环运行的占用资源情况待后续补充
    ui->statusBar->showMessage(tr("读图时间：- ，算法处理时间：-"),0);
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




