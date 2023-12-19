#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlError>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化界面
    InitUi();
    //查看数据库驱动
    //qDebug()<< "Database driver has： " << QSqlDatabase::drivers();
    //初始化数据库
    //InitsqliteBase();

    //信号和槽设置

}



/**
 * @brief MainWindow::InitUi
 */
void MainWindow:: InitUi(){

    listImage = new UserListWidgets();
    ui->gridLayout_8->addWidget(listImage);

    window = new UserGraphicsView();
    ui->gridLayout_9->addWidget(window->getWindow());

    qDebug()<<"缩略图的个数："<<listImage->getNumberofItem()<<endl;
    connect(listImage,&UserListWidgets::enableConnect,this,&MainWindow::setShowImage);
    //listImage->setConnect(window->m_window);
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
 * @brief MainWindow::on_once_action_triggered
 *
 */
void MainWindow::on_once_action_triggered()
{

}
