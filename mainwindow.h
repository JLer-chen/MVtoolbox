#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userlistwidgets.h"
#include "usergraphicsview.h"
#include "userlwidgetsitem.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitUi();

    void InitsqliteBase();
    void setShowImage();
private slots:
    void on_once_action_triggered();

private:
    Ui::MainWindow *ui;
    UserListWidgets *listImage;
    UserGraphicsView *window;
};

#endif // MAINWINDOW_H
