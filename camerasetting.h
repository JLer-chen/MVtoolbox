#ifndef CAMERASETTING_H
#define CAMERASETTING_H

#include <QDialog>

namespace Ui {
class camerasetting;
}

class camerasetting : public QDialog
{
    Q_OBJECT

public:
    explicit camerasetting(QWidget *parent = nullptr);
    ~camerasetting();
    QString get_storePath();
    QString get_pluginPath();
private slots:
    void slot_storeButtonClick();
    void slot_pluginButtonClick();
    void slot_confirmButtonClick();
    void slot_cancelButtonClick();

private:
    Ui::camerasetting *ui;
    QString storePath;
    QString pluginPath;
};

#endif // CAMERASETTING_H
