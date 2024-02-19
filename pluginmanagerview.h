#ifndef PLUGINMANAGERVIEW_H
#define PLUGINMANAGERVIEW_H

#include <QWidget>
#include "mainplugins.h"
#include <QVector>
#include <QListWidgetItem>
namespace Ui {
class pluginManagerView;
}

class pluginManagerView : public QWidget
{
    Q_OBJECT

public:
    explicit pluginManagerView(QWidget *parent = nullptr);
    ~pluginManagerView();
    bool setAlgorithmPanel(int currentRow);
    void setAlgorithmTree();
    bool loadPlugins(QString path);
    void initPlugins(QString);
    int getOnceTimer();
    bool isSelected();
public slots:
    void process(QImage image);

signals:
    void sendDstImage(QString );
private:
    Ui::pluginManagerView *ui;
    QString curPluginName;
    int curIndex ;
    QVector<MainInterface* > plugins;
    int number;
    MainInterface *curPlugin ;
    QWidget* tempPanel;
    int onceTimer ;
    bool isInit = false;


};

#endif // PLUGINMANAGERVIEW_H
