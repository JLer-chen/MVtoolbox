/********************************************************************************
** Form generated from reading UI file 'camerasetting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERASETTING_H
#define UI_CAMERASETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_camerasetting
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *storeButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pluginButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *camerasetting)
    {
        if (camerasetting->objectName().isEmpty())
            camerasetting->setObjectName(QString::fromUtf8("camerasetting"));
        camerasetting->resize(500, 300);
        camerasetting->setMinimumSize(QSize(500, 250));
        gridLayout_2 = new QGridLayout(camerasetting);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(camerasetting);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(camerasetting);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        storeButton = new QPushButton(camerasetting);
        storeButton->setObjectName(QString::fromUtf8("storeButton"));

        gridLayout->addWidget(storeButton, 0, 2, 1, 1);

        label_2 = new QLabel(camerasetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(camerasetting);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        pluginButton = new QPushButton(camerasetting);
        pluginButton->setObjectName(QString::fromUtf8("pluginButton"));

        gridLayout->addWidget(pluginButton, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        confirmButton = new QPushButton(camerasetting);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        gridLayout_2->addWidget(confirmButton, 1, 1, 1, 1);

        cancelButton = new QPushButton(camerasetting);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 1, 2, 1, 1);


        retranslateUi(camerasetting);

        QMetaObject::connectSlotsByName(camerasetting);
    } // setupUi

    void retranslateUi(QDialog *camerasetting)
    {
        camerasetting->setWindowTitle(QApplication::translate("camerasetting", "Dialog", nullptr));
        label->setText(QApplication::translate("camerasetting", "\345\233\276\345\203\217\345\255\230\345\202\250\350\267\257\345\276\204\357\274\232", nullptr));
        storeButton->setText(QString());
        label_2->setText(QApplication::translate("camerasetting", "\346\217\222\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        pluginButton->setText(QString());
        confirmButton->setText(QApplication::translate("camerasetting", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QApplication::translate("camerasetting", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class camerasetting: public Ui_camerasetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERASETTING_H
