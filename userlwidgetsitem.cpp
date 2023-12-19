#include "userlwidgetsitem.h"
#include "ui_userlwidgetsitem.h"
#include <QImage>
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
    ui->label->setPixmap(QPixmap(path).scaled(measure,measure,Qt::KeepAspectRatio));
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
    emit sendPath(imagePath);
}
