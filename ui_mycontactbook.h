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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyContactBook
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *clearButton;
    QPushButton *searchButton;
    QPushButton *importButton;
    QPushButton *exportButton;
    QPushButton *exitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyContactBook)
    {
        if (MyContactBook->objectName().isEmpty())
            MyContactBook->setObjectName("MyContactBook");
        MyContactBook->resize(800, 600);
        centralwidget = new QWidget(MyContactBook);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);

        verticalLayout->addWidget(tableWidget);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(20, 20, 20, 20);
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEdit_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName("lineEdit_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEdit_4);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(addButton);

        editButton = new QPushButton(centralwidget);
        editButton->setObjectName("editButton");
        editButton->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(editButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(deleteButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(clearButton);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        searchButton->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(searchButton);

        importButton = new QPushButton(centralwidget);
        importButton->setObjectName("importButton");
        importButton->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(importButton);

        exportButton = new QPushButton(centralwidget);
        exportButton->setObjectName("exportButton");
        exportButton->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(exportButton);

        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setMinimumSize(QSize(0, 40));

        horizontalLayout->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout);

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
        groupBox->setTitle(QCoreApplication::translate("MyContactBook", "\350\201\257\347\265\241\344\272\272\350\263\207\350\250\212", nullptr));
        label->setText(QCoreApplication::translate("MyContactBook", "\345\255\270\350\231\237\357\274\232", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MyContactBook", "\350\253\213\350\274\270\345\205\245\345\255\270\350\231\237", nullptr));
        label_2->setText(QCoreApplication::translate("MyContactBook", "\347\217\255\347\264\232\357\274\232", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MyContactBook", "\350\253\213\350\274\270\345\205\245\347\217\255\347\264\232", nullptr));
        label_3->setText(QCoreApplication::translate("MyContactBook", "\345\247\223\345\220\215\357\274\232", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MyContactBook", "\350\253\213\350\274\270\345\205\245\345\247\223\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("MyContactBook", "\351\233\273\350\251\261\357\274\232", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MyContactBook", "\350\253\213\350\274\270\345\205\245\351\233\273\350\251\261", nullptr));
        addButton->setText(QCoreApplication::translate("MyContactBook", "\342\236\225 \346\226\260\345\242\236", nullptr));
#if QT_CONFIG(tooltip)
        addButton->setToolTip(QCoreApplication::translate("MyContactBook", "\346\226\260\345\242\236\350\201\257\347\265\241\344\272\272", nullptr));
#endif // QT_CONFIG(tooltip)
        editButton->setText(QCoreApplication::translate("MyContactBook", "\342\234\217\357\270\217 \347\267\250\350\274\257", nullptr));
#if QT_CONFIG(tooltip)
        editButton->setToolTip(QCoreApplication::translate("MyContactBook", "\347\267\250\350\274\257\351\201\270\344\270\255\347\232\204\350\201\257\347\265\241\344\272\272", nullptr));
#endif // QT_CONFIG(tooltip)
        deleteButton->setText(QCoreApplication::translate("MyContactBook", "\360\237\227\221\357\270\217 \345\210\252\351\231\244", nullptr));
#if QT_CONFIG(tooltip)
        deleteButton->setToolTip(QCoreApplication::translate("MyContactBook", "\345\210\252\351\231\244\351\201\270\344\270\255\347\232\204\350\201\257\347\265\241\344\272\272", nullptr));
#endif // QT_CONFIG(tooltip)
        clearButton->setText(QCoreApplication::translate("MyContactBook", "\360\237\247\271 \346\270\205\351\231\244", nullptr));
#if QT_CONFIG(tooltip)
        clearButton->setToolTip(QCoreApplication::translate("MyContactBook", "\346\270\205\351\231\244\350\274\270\345\205\245\350\241\250\345\226\256", nullptr));
#endif // QT_CONFIG(tooltip)
        searchButton->setText(QCoreApplication::translate("MyContactBook", "\360\237\224\215 \346\220\234\345\260\213", nullptr));
#if QT_CONFIG(tooltip)
        searchButton->setToolTip(QCoreApplication::translate("MyContactBook", "\346\220\234\345\260\213\350\201\257\347\265\241\344\272\272\357\274\210\345\234\250\345\247\223\345\220\215\346\254\204\350\274\270\345\205\245\351\227\234\351\215\265\345\255\227\357\274\211", nullptr));
#endif // QT_CONFIG(tooltip)
        importButton->setText(QCoreApplication::translate("MyContactBook", "\360\237\223\245 \345\214\257\345\205\245", nullptr));
#if QT_CONFIG(tooltip)
        importButton->setToolTip(QCoreApplication::translate("MyContactBook", "\345\276\236\346\252\224\346\241\210\345\214\257\345\205\245\350\201\257\347\265\241\344\272\272", nullptr));
#endif // QT_CONFIG(tooltip)
        exportButton->setText(QCoreApplication::translate("MyContactBook", "\360\237\223\244 \345\214\257\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        exportButton->setToolTip(QCoreApplication::translate("MyContactBook", "\345\214\257\345\207\272\350\201\257\347\265\241\344\272\272\350\207\263\346\252\224\346\241\210", nullptr));
#endif // QT_CONFIG(tooltip)
        exitButton->setText(QCoreApplication::translate("MyContactBook", "\360\237\232\252 \347\265\220\346\235\237", nullptr));
#if QT_CONFIG(tooltip)
        exitButton->setToolTip(QCoreApplication::translate("MyContactBook", "\347\265\220\346\235\237\347\250\213\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MyContactBook: public Ui_MyContactBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCONTACTBOOK_H
