#ifndef USERGRAPHICSVIEW_H
#define USERGRAPHICSVIEW_H
#include "myview.h"
#include <QGraphicsScene>
#include "userimageitem.h"
class UserGraphicsView : public QWidget
{
public:
    UserGraphicsView();
    Myview* getWindow();
    void showImage(QString path);
private:
    Myview *m_window;
    QGraphicsScene *scene;
    UserImageItem* tempItem ;
};

#endif // USERGRAPHICSVIEW_H
