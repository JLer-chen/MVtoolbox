/********************************************************************************
** Form generated from reading UI file 'userlwidgetsitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLWIDGETSITEM_H
#define UI_USERLWIDGETSITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserLWidgetsItem
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *UserLWidgetsItem)
    {
        if (UserLWidgetsItem->objectName().isEmpty())
            UserLWidgetsItem->setObjectName(QString::fromUtf8("UserLWidgetsItem"));
        UserLWidgetsItem->resize(400, 300);
        verticalLayout = new QVBoxLayout(UserLWidgetsItem);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(UserLWidgetsItem);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        label = new QLabel(UserLWidgetsItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::Panel);
        label->setLineWidth(4);

        verticalLayout->addWidget(label);


        retranslateUi(UserLWidgetsItem);

        QMetaObject::connectSlotsByName(UserLWidgetsItem);
    } // setupUi

    void retranslateUi(QWidget *UserLWidgetsItem)
    {
        UserLWidgetsItem->setWindowTitle(QApplication::translate("UserLWidgetsItem", "Form", nullptr));
        pushButton->setText(QApplication::translate("UserLWidgetsItem", "\346\230\276\347\244\272", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserLWidgetsItem: public Ui_UserLWidgetsItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLWIDGETSITEM_H
