/********************************************************************************
** Form generated from reading UI file 'userlistwidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLISTWIDGETS_H
#define UI_USERLISTWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserListWidgets
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidget;

    void setupUi(QWidget *UserListWidgets)
    {
        if (UserListWidgets->objectName().isEmpty())
            UserListWidgets->setObjectName(QString::fromUtf8("UserListWidgets"));
        UserListWidgets->resize(986, 132);
        verticalLayout = new QVBoxLayout(UserListWidgets);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(UserListWidgets);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(UserListWidgets);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setFlow(QListView::LeftToRight);

        verticalLayout->addWidget(listWidget);


        retranslateUi(UserListWidgets);

        QMetaObject::connectSlotsByName(UserListWidgets);
    } // setupUi

    void retranslateUi(QWidget *UserListWidgets)
    {
        UserListWidgets->setWindowTitle(QApplication::translate("UserListWidgets", "Form", nullptr));
        pushButton->setText(QApplication::translate("UserListWidgets", "open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserListWidgets: public Ui_UserListWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLISTWIDGETS_H
