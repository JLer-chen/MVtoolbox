/********************************************************************************
** Form generated from reading UI file 'pluginmanagerview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINMANAGERVIEW_H
#define UI_PLUGINMANAGERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pluginManagerView
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QListWidget *listWidget;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;

    void setupUi(QWidget *pluginManagerView)
    {
        if (pluginManagerView->objectName().isEmpty())
            pluginManagerView->setObjectName(QString::fromUtf8("pluginManagerView"));
        pluginManagerView->resize(617, 647);
        horizontalLayout = new QHBoxLayout(pluginManagerView);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(pluginManagerView);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(150, 0));
        splitter->addWidget(listWidget);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(350, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(10);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        splitter->addWidget(frame);

        horizontalLayout->addWidget(splitter);


        retranslateUi(pluginManagerView);

        QMetaObject::connectSlotsByName(pluginManagerView);
    } // setupUi

    void retranslateUi(QWidget *pluginManagerView)
    {
        pluginManagerView->setWindowTitle(QApplication::translate("pluginManagerView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pluginManagerView: public Ui_pluginManagerView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINMANAGERVIEW_H
