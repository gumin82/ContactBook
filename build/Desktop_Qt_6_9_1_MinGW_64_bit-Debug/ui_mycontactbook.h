/********************************************************************************
** Form generated from reading UI file 'mycontactbook.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCONTACTBOOK_H
#define UI_MYCONTACTBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyContactBook
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyContactBook)
    {
        if (MyContactBook->objectName().isEmpty())
            MyContactBook->setObjectName("MyContactBook");
        MyContactBook->resize(800, 600);
        centralwidget = new QWidget(MyContactBook);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_2);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEdit_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEdit_4);


        gridLayout_2->addLayout(formLayout, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        MyContactBook->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyContactBook);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MyContactBook->setMenuBar(menubar);
        statusbar = new QStatusBar(MyContactBook);
        statusbar->setObjectName("statusbar");
        MyContactBook->setStatusBar(statusbar);

        retranslateUi(MyContactBook);

        QMetaObject::connectSlotsByName(MyContactBook);
    } // setupUi

    void retranslateUi(QMainWindow *MyContactBook)
    {
        MyContactBook->setWindowTitle(QCoreApplication::translate("MyContactBook", "MyContactBook", nullptr));
        label->setText(QCoreApplication::translate("MyContactBook", "\345\255\270\350\231\237:", nullptr));
        label_2->setText(QCoreApplication::translate("MyContactBook", "\347\217\255\347\264\232:", nullptr));
        label_3->setText(QCoreApplication::translate("MyContactBook", "\345\247\223\345\220\215:", nullptr));
        label_4->setText(QCoreApplication::translate("MyContactBook", "\351\233\273\350\251\261:", nullptr));
        pushButton->setText(QCoreApplication::translate("MyContactBook", "\346\226\260\345\242\236", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MyContactBook", "\345\214\257\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyContactBook: public Ui_MyContactBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCONTACTBOOK_H
