#ifndef USERLWIDGETSITEM_H
#define USERLWIDGETSITEM_H

#include <QWidget>
#include <QPushButton>
namespace Ui {
class UserLWidgetsItem;
}

class UserLWidgetsItem : public QWidget
{
    Q_OBJECT

public:
    explicit UserLWidgetsItem(QWidget *parent = nullptr);
    ~UserLWidgetsItem();
    void addLitimg(QString &path ,int32_t measure);
    QPushButton* getButtonClick();

private slots:
    void on_pushButton_clicked();

signals:
    void sendPath(QString path);
private:
    Ui::UserLWidgetsItem *ui;
    QString imagePath;
};

#endif // USERLWIDGETSITEM_H
