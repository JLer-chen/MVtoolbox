#include "pluginmanagerview.h"
#include "ui_pluginmanagerview.h"
#include <QDir>
#include <QPluginLoader>
#include <QDebug>
#include <QLabel>
#include <QTime>
#include <QMessageBox>
pluginManagerView::pluginManagerView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pluginManagerView),
    curIndex(-1),
    curPlugin(nullptr)
{
    ui->setupUi(this);
}

pluginManagerView::~pluginManagerView()
{
    delete ui;
}

bool pluginManagerView::setAlgorithmPanel(int currentRow)
{
    qDebug()<<"enter setalgorithpanel";
    if(!isInit){
        qDebug()<<"have not inited";
        QMessageBox::information(this,"information",tr("check storage"));
        return false;
    }
    curIndex = currentRow;
    curPlugin = plugins.at(curIndex);
    MainInterface* curPlugin = plugins.at(curIndex);
    ui->gridLayout->removeWidget(tempPanel);
    QWidget* curPanel = curPlugin->getSettingPanel();
    ui->gridLayout->addWidget(curPanel);
    tempPanel = curPanel;
    return true;
}

void pluginManagerView::setAlgorithmTree()
{
    QStringList pluginName;
    for(auto i:plugins){
        pluginName.push_back(i->name());
        //QLabel* item =new QLabel(i->name());
        ui->listWidget->addItem(i->name());
    }
    connect(ui->listWidget,&QListWidget::currentRowChanged,this
            ,&pluginManagerView::setAlgorithmPanel);

}
/**
 * @brief pluginManagerView::loadPlugins
 * @param path 插件所在目录由主程序提供
 * @return
 */
bool pluginManagerView::loadPlugins(QString path)
{
    QDir pluginsDir(path);

    // 遍历插件目录
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        qDebug()<<"String:"<<pluginsDir.absoluteFilePath(fileName)<<endl;
        qDebug() << "Plugin loading failed:" << pluginLoader.errorString();
        QObject *plugin = pluginLoader.instance();
        qDebug()<<"plugin:"<<plugin<<endl;
        if (plugin) {
            MainInterface *temp = qobject_cast<MainInterface *>(plugin);
            if (temp){
                plugins.push_back(temp);
                number++;
            }
        }
    }
    //如果无可以用的插件则返回false
    if(number==0){
        return false;
    }
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<number;
    return true;
}

void pluginManagerView::initPlugins(QString storePath)
{
    for(auto i :plugins){
        i->Init(storePath);
    }
    isInit = true;
}

int pluginManagerView::getOnceTimer()
{
    return onceTimer;
}

bool pluginManagerView::isSelected()
{
    return curIndex==-1?false:true;
}



void pluginManagerView::process(QImage image)
{
    if(curPlugin == nullptr){
        qDebug()<<"curPlugin == nullptr";
        return ;
    }
    qDebug()<<"enter process";
    int before  = QTime::currentTime().msecsSinceStartOfDay();
    QString ImagePath = curPlugin->execute(image);
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"tempImage addr: "<<ImagePath;
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"execute 耗时："<<QTime::currentTime().msecsSinceStartOfDay() - before;
    emit sendDstImage(ImagePath);
    onceTimer = QTime::currentTime().msecsSinceStartOfDay() - before;
    qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
           <<"process 耗时："<<QTime::currentTime().msecsSinceStartOfDay() - before;
}
