#include "userlwidgetsitem.h"
#include "ui_userlwidgetsitem.h"
#include <QImage>
#include <QDebug>
UserLWidgetsItem::UserLWidgetsItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserLWidgetsItem)
{
    ui->setupUi(this);
}

UserLWidgetsItem::~UserLWidgetsItem()
{
    delete ui;
}

void UserLWidgetsItem::addLitimg(QString &path, int32_t measure)
{
    QPixmap temp ;
    temp.load(path);
     qDebug()<<"temp addr"<<&temp;
    QPixmap temp1 = temp.scaled(measure,measure,Qt::KeepAspectRatio);
    qDebug()<<"temp1 addr:"<<&temp1;
    ui->label->setPixmap(temp1);
    imagePath = path;
}

QPushButton* UserLWidgetsItem::getButtonClick()
{
    return ui->pushButton;
}


/**
 * @brief UserLWidgetsItem::on_pushButton_clicked
 * add image to scene
 */
void UserLWidgetsItem::on_pushButton_clicked()
{
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"send "<<imagePath;
    emit sendPath(imagePath);
}
