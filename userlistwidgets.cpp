#include "userlistwidgets.h"
#include "ui_userlistwidgets.h"
#include <QFileDialog>
#include <QDebug>

#include "usergraphicsview.h"
UserListWidgets::UserListWidgets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserListWidgets)
{
    ui->setupUi(this);
}

UserListWidgets::~UserListWidgets()
{
    delete ui;
}

void UserListWidgets::updateLitimg()
{
    QListWidget *imglist =  ui->listWidget;
    imglist->clear();
    imglist->setViewMode(QListView::ListMode);
    imglist->setIconSize(QSize(imglist->height()-200,imglist->height()-200));
    imglist->setSpacing(15);
    imglist->setResizeMode(QListWidget::Fixed);
    imglist->setItemAlignment(Qt::AlignCenter);

    imglist->setMovement(QListWidget::Static);
    itemList.clear();
    for(QString tmp : m_imagelist){
        UserLWidgetsItem *item = new UserLWidgetsItem();
        item->addLitimg(tmp,imglist->height());
        QListWidgetItem *imageItem = new QListWidgetItem();
        itemList.push_back(item);
        imageItem->setSizeHint(QSize(imglist->height()-20,imglist->height()-20));
        imglist->addItem(imageItem);

        imglist->setItemWidget(imageItem,item);

        //每张缩略图在显示阶段就设置信号量和槽
        //connect(item,item->getButtonClick()->click(),)
    }
    emit enableConnect();
}

/**
 * @brief UserListWidgets::getNumberofItem
 * @return
 */
int UserListWidgets::getNumberofItem()
{
    return m_imagelist.size();
}

UserLWidgetsItem *UserListWidgets::getItem(int num)
{
    return itemList.at(num);
}


QStringList UserListWidgets::getImageList()
{
    return m_imagelist;
}

//void UserListWidgets::setConnect(Myview *window)
//{
//    connect()
//}

void UserListWidgets::on_pushButton_clicked()
{
    QFileDialog *file = new QFileDialog(this);
    file->setWindowTitle(tr("打开图片"));
    file->setDirectory("D:/888/image.vary.jpg/image.vary.jpg");
    file->setNameFilter(tr("Image(*.png *jpg *.bmp)"));
    file->setFileMode(QFileDialog::ExistingFiles);
    file->setViewMode(QFileDialog::Detail);


    if(file->exec()){
        m_imagelist = file->selectedFiles();
        updateLitimg();
    }
    for(auto imgpath: m_imagelist){
        qDebug()<<imgpath<<endl;
    }
}
