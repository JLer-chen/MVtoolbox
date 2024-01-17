 #ifndef USERLISTWIDGETS_H
#define USERLISTWIDGETS_H

#include <QWidget>
#include <QVector>
#include "myview.h"
#include "userlwidgetsitem.h"
namespace Ui {
class UserListWidgets;
}

class UserListWidgets : public QWidget
{
    Q_OBJECT

public:
    explicit UserListWidgets(QWidget *parent = nullptr);
    ~UserListWidgets();
    void updateLitimg();
    void setConnect(Myview* window);
    int getNumberofItem();
    UserLWidgetsItem* getItem(int num);

    //返回选择所有图片的路径
    QStringList getImageList();
private slots:
    void on_pushButton_clicked();

signals:
    void enableConnect();
private:
    Ui::UserListWidgets *ui;
    QStringList m_imagelist;
    QVector<UserLWidgetsItem* > itemList;
};

#endif // USERLISTWIDGETS_H
