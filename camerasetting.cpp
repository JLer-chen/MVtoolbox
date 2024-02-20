#include "camerasetting.h"
#include "ui_camerasetting.h"
#include <QFile>
#include <QFileDialog>
#include <QDebug>
camerasetting::camerasetting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::camerasetting)
{
    ui->setupUi(this);
    connect(this->ui->storeButton,&QPushButton::clicked,this,&camerasetting::slot_storeButtonClick);
    connect(this->ui->pluginButton,&QPushButton::clicked,this,&camerasetting::slot_pluginButtonClick);
    connect(this->ui->confirmButton,&QPushButton::clicked,this,&camerasetting::slot_confirmButtonClick);
    connect(this->ui->cancelButton,&QPushButton::clicked,this,&camerasetting::slot_cancelButtonClick);
    this->ui->storeButton->setIcon(QIcon(":/images/orange_path.png"));
    this->ui->pluginButton->setIcon(QIcon(":/images/orange_path.png"));
}

camerasetting::~camerasetting()
{
    delete ui;
}

QString camerasetting::get_storePath()
{
    return storePath;
}

QString camerasetting::get_pluginPath()
{
    return pluginPath;
}

void camerasetting::slot_storeButtonClick()
{
    qDebug()<<"enter slot_store";
    storePath = QFileDialog::getExistingDirectory();
    ui->lineEdit->setText(storePath);
}

void camerasetting::slot_pluginButtonClick()
{
    qDebug()<<"enter slot_plugin";
    pluginPath = QFileDialog::getExistingDirectory();
    ui->lineEdit_2->setText(pluginPath);
}

void camerasetting::slot_confirmButtonClick()
{
    this->accept();
}

void camerasetting::slot_cancelButtonClick()
{
    storePath = "";
    pluginPath = "";
    ui->lineEdit->setText(storePath);
    ui->lineEdit_2->setText(pluginPath);
    this->reject();
}


