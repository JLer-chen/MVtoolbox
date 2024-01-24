#include "userlistwidgets.h"
#include "ui_userlistwidgets.h"
#include <QFileDialog>
#include <QDebug>
#include <QProgressBar>
#include <QLabel>
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
    //耗时操作进度条显示
    QWidget widget ;
    //QVBoxLayout *layout = new QVBoxLayout(this);
    QProgressBar bar ;
    bar.setParent(&widget);
    //layout->addWidget(bar);
    //QLabel* label =new QLabel(widget);
    //layout->addWidget(label);
    //label->setText(tr("图片已全部读取"));
    widget.setFixedSize(600,200);
    bar.setGeometry(20,80,280,30);
    bar.setRange(0,100);
    bar.setOrientation(Qt::Horizontal);
    bar.setValue(0);
    int number = 0;
    widget.show();
    for(QString tmp : m_imagelist){
        UserLWidgetsItem *item = new UserLWidgetsItem();
        item->addLitimg(tmp,imglist->height());
        QListWidgetItem *imageItem = new QListWidgetItem();
        itemList.push_back(item);
        imageItem->setSizeHint(QSize(imglist->height()-20,imglist->height()-20));
        imglist->addItem(imageItem);

        imglist->setItemWidget(imageItem,item);
        number++;
        bar.setValue(float(number)*100.0/m_imagelist.size());
        bar.setFormat("the progress:"+QString::number
                       (float(number)*100.0/m_imagelist.size(), 'f', 1)+"%");
        QCoreApplication::processEvents();
    }
    widget.hide();
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
