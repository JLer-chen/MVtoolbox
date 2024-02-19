/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *camera_action;
    QAction *setting_action;
    QAction *once_action;
    QAction *loop_action;
    QAction *help_action;
    QAction *clear_action;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_9;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_8;
    QWidget *tab_2;
    QGridLayout *gridLayout_7;
    QTableWidget *tableWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1042, 938);
        camera_action = new QAction(MainWindow);
        camera_action->setObjectName(QString::fromUtf8("camera_action"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/blue_camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/orange_camera.png"), QSize(), QIcon::Selected, QIcon::On);
        camera_action->setIcon(icon);
        setting_action = new QAction(MainWindow);
        setting_action->setObjectName(QString::fromUtf8("setting_action"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        setting_action->setIcon(icon1);
        once_action = new QAction(MainWindow);
        once_action->setObjectName(QString::fromUtf8("once_action"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/blue_once.png"), QSize(), QIcon::Normal, QIcon::Off);
        once_action->setIcon(icon2);
        loop_action = new QAction(MainWindow);
        loop_action->setObjectName(QString::fromUtf8("loop_action"));
        loop_action->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/blue_loop.png"), QSize(), QIcon::Normal, QIcon::Off);
        loop_action->setIcon(icon3);
        help_action = new QAction(MainWindow);
        help_action->setObjectName(QString::fromUtf8("help_action"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/blue_help.png"), QSize(), QIcon::Normal, QIcon::Off);
        help_action->setIcon(icon4);
        clear_action = new QAction(MainWindow);
        clear_action->setObjectName(QString::fromUtf8("clear_action"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clear_action->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(500, 0));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(4);
        gridLayout_10 = new QGridLayout(frame_2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        gridLayout_10->addLayout(gridLayout_2, 0, 0, 1, 1);


        horizontalLayout->addWidget(frame_2);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMinimumSize(QSize(0, 0));
        splitter->setLineWidth(4);
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter_2 = new QSplitter(widget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(500, 700));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));

        gridLayout->addLayout(gridLayout_9, 0, 0, 1, 1);

        splitter_2->addWidget(frame);
        tabWidget = new QTabWidget(splitter_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        gridLayout_3 = new QGridLayout(tab1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));

        gridLayout_3->addLayout(gridLayout_8, 0, 0, 1, 1);

        tabWidget->addTab(tab1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_7 = new QGridLayout(tab_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_7->addWidget(tableWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        textEdit = new QTextEdit(tab_3);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_4->addWidget(textEdit, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        splitter_2->addWidget(tabWidget);

        verticalLayout->addWidget(splitter_2);

        splitter->addWidget(widget);

        horizontalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1042, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(camera_action);
        mainToolBar->addAction(setting_action);
        mainToolBar->addAction(once_action);
        mainToolBar->addAction(loop_action);
        mainToolBar->addAction(help_action);
        mainToolBar->addAction(clear_action);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        camera_action->setText(QApplication::translate("MainWindow", "\347\233\270\346\234\272", nullptr));
#ifndef QT_NO_TOOLTIP
        camera_action->setToolTip(QApplication::translate("MainWindow", "\347\233\270\346\234\272\350\256\276\347\275\256", nullptr));
#endif // QT_NO_TOOLTIP
        setting_action->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        once_action->setText(QApplication::translate("MainWindow", "\345\215\225\346\254\241\350\277\220\350\241\214", nullptr));
#ifndef QT_NO_TOOLTIP
        once_action->setToolTip(QApplication::translate("MainWindow", "\345\215\225\346\254\241\350\277\220\350\241\214", nullptr));
#endif // QT_NO_TOOLTIP
        loop_action->setText(QApplication::translate("MainWindow", "\345\276\252\347\216\257\350\277\220\350\241\214", nullptr));
#ifndef QT_NO_TOOLTIP
        loop_action->setToolTip(QApplication::translate("MainWindow", "\345\276\252\347\216\257\350\277\220\350\241\214", nullptr));
#endif // QT_NO_TOOLTIP
        help_action->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
#ifndef QT_NO_TOOLTIP
        help_action->setToolTip(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
#endif // QT_NO_TOOLTIP
        clear_action->setText(QApplication::translate("MainWindow", "\346\270\205\347\220\206", nullptr));
#ifndef QT_NO_TOOLTIP
        clear_action->setToolTip(QApplication::translate("MainWindow", "\346\270\205\347\220\206", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "\347\274\251\347\225\245\345\233\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "age", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "sex", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\346\225\260\345\255\246\350\200\201\345\270\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\350\213\261\350\257\255\350\200\201\345\270\210", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
