/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *targetBaseComboBox;
    QComboBox *sourceBaseComboBox;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_6;
    QLineEdit *inputLineEdit;
    QGridLayout *gridLayout_4;
    QPushButton *convertButton;
    QGridLayout *gridLayout_5;
    QLabel *label_7;
    QLineEdit *outputLineEdit;
    QLabel *label_4;
    QGridLayout *gridLayout_6;
    QLabel *label_8;
    QLabel *label_5;
    QLineEdit *errorLineEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(500, 350));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        targetBaseComboBox = new QComboBox(centralwidget);
        targetBaseComboBox->addItem(QString());
        targetBaseComboBox->addItem(QString());
        targetBaseComboBox->addItem(QString());
        targetBaseComboBox->setObjectName("targetBaseComboBox");

        gridLayout_2->addWidget(targetBaseComboBox, 1, 1, 1, 1);

        sourceBaseComboBox = new QComboBox(centralwidget);
        sourceBaseComboBox->addItem(QString());
        sourceBaseComboBox->addItem(QString());
        sourceBaseComboBox->addItem(QString());
        sourceBaseComboBox->setObjectName("sourceBaseComboBox");

        gridLayout_2->addWidget(sourceBaseComboBox, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        gridLayout_3->addWidget(label_6, 0, 1, 1, 1);

        inputLineEdit = new QLineEdit(centralwidget);
        inputLineEdit->setObjectName("inputLineEdit");
        inputLineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid #666;\n"
"border-radius: 4px;\n"
"padding: 4px;\n"
"color: white;"));

        gridLayout_3->addWidget(inputLineEdit, 0, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        convertButton = new QPushButton(centralwidget);
        convertButton->setObjectName("convertButton");
        convertButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(convertButton, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        gridLayout_5->addWidget(label_7, 0, 1, 1, 1);

        outputLineEdit = new QLineEdit(centralwidget);
        outputLineEdit->setObjectName("outputLineEdit");
        outputLineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid #666;\n"
"border-radius: 4px;\n"
"padding: 4px;\n"
"color: white;"));
        outputLineEdit->setReadOnly(true);

        gridLayout_5->addWidget(outputLineEdit, 0, 2, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout_5->addWidget(label_4, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_5);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");

        gridLayout_6->addWidget(label_8, 0, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);

        errorLineEdit = new QLineEdit(centralwidget);
        errorLineEdit->setObjectName("errorLineEdit");
        errorLineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid #666;\n"
"border-radius: 4px;\n"
"padding: 4px;\n"
"color: red;"));
        errorLineEdit->setReadOnly(true);

        gridLayout_6->addWidget(errorLineEdit, 0, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_6);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Number System Converter", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\207\320\275\320\260\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\320\260\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\260:", nullptr));
        targetBaseComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "10", nullptr));
        targetBaseComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        targetBaseComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "8", nullptr));

        sourceBaseComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "10", nullptr));
        sourceBaseComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        sourceBaseComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "8", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\276:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\343\205\244\343\205\244 ", nullptr));
        convertButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\343\205\244\343\205\244\343\205\244\343\205\244\343\205\244", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\343\205\244\343\205\244\343\205\244\343\205\244\343\205\244\343\205\244", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
