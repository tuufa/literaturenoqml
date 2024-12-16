/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_title;
    QLineEdit *lineEdit_title;
    QLabel *label_category;
    QComboBox *comboBox_category;
    QLabel *label_rating;
    QSpinBox *spinBox_rating;
    QLabel *label_author;
    QLineEdit *lineEdit_author;
    QLabel *label_date;
    QDateEdit *dateEdit_date;
    QLabel *label_difficulty;
    QComboBox *comboBox_difficulty;
    QTableWidget *tableWidget_books;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *pushButton_add;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_recommend;
    QHBoxLayout *horizontalLayout_buttons1;
    QPushButton *pushButton_checked;
    QPushButton *pushButton_export;
    QPushButton *pushButton_import;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 635);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_title = new QLabel(centralwidget);
        label_title->setObjectName("label_title");

        gridLayout->addWidget(label_title, 0, 0, 1, 1);

        lineEdit_title = new QLineEdit(centralwidget);
        lineEdit_title->setObjectName("lineEdit_title");

        gridLayout->addWidget(lineEdit_title, 0, 1, 1, 1);

        label_category = new QLabel(centralwidget);
        label_category->setObjectName("label_category");

        gridLayout->addWidget(label_category, 1, 0, 1, 1);

        comboBox_category = new QComboBox(centralwidget);
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->setObjectName("comboBox_category");

        gridLayout->addWidget(comboBox_category, 1, 1, 1, 1);

        label_rating = new QLabel(centralwidget);
        label_rating->setObjectName("label_rating");

        gridLayout->addWidget(label_rating, 2, 0, 1, 1);

        spinBox_rating = new QSpinBox(centralwidget);
        spinBox_rating->setObjectName("spinBox_rating");
        spinBox_rating->setMinimum(1);
        spinBox_rating->setMaximum(10);

        gridLayout->addWidget(spinBox_rating, 2, 1, 1, 1);

        label_author = new QLabel(centralwidget);
        label_author->setObjectName("label_author");

        gridLayout->addWidget(label_author, 3, 0, 1, 1);

        lineEdit_author = new QLineEdit(centralwidget);
        lineEdit_author->setObjectName("lineEdit_author");

        gridLayout->addWidget(lineEdit_author, 3, 1, 1, 1);

        label_date = new QLabel(centralwidget);
        label_date->setObjectName("label_date");

        gridLayout->addWidget(label_date, 4, 0, 1, 1);

        dateEdit_date = new QDateEdit(centralwidget);
        dateEdit_date->setObjectName("dateEdit_date");
        dateEdit_date->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_date, 4, 1, 1, 1);

        label_difficulty = new QLabel(centralwidget);
        label_difficulty->setObjectName("label_difficulty");

        gridLayout->addWidget(label_difficulty, 5, 0, 1, 1);

        comboBox_difficulty = new QComboBox(centralwidget);
        comboBox_difficulty->addItem(QString());
        comboBox_difficulty->addItem(QString());
        comboBox_difficulty->addItem(QString());
        comboBox_difficulty->setObjectName("comboBox_difficulty");

        gridLayout->addWidget(comboBox_difficulty, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        tableWidget_books = new QTableWidget(centralwidget);
        if (tableWidget_books->columnCount() < 7)
            tableWidget_books->setColumnCount(7);
        tableWidget_books->setObjectName("tableWidget_books");
        tableWidget_books->setColumnCount(7);

        verticalLayout->addWidget(tableWidget_books);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName("horizontalLayout_buttons");
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName("pushButton_add");

        horizontalLayout_buttons->addWidget(pushButton_add);

        pushButton_delete = new QPushButton(centralwidget);
        pushButton_delete->setObjectName("pushButton_delete");

        horizontalLayout_buttons->addWidget(pushButton_delete);

        pushButton_recommend = new QPushButton(centralwidget);
        pushButton_recommend->setObjectName("pushButton_recommend");

        horizontalLayout_buttons->addWidget(pushButton_recommend);


        verticalLayout->addLayout(horizontalLayout_buttons);

        horizontalLayout_buttons1 = new QHBoxLayout();
        horizontalLayout_buttons1->setObjectName("horizontalLayout_buttons1");
        pushButton_checked = new QPushButton(centralwidget);
        pushButton_checked->setObjectName("pushButton_checked");

        horizontalLayout_buttons1->addWidget(pushButton_checked);

        pushButton_export = new QPushButton(centralwidget);
        pushButton_export->setObjectName("pushButton_export");

        horizontalLayout_buttons1->addWidget(pushButton_export);

        pushButton_import = new QPushButton(centralwidget);
        pushButton_import->setObjectName("pushButton_import");

        horizontalLayout_buttons1->addWidget(pushButton_import);


        verticalLayout->addLayout(horizontalLayout_buttons1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \321\203\321\207\320\265\321\202\320\260 \320\277\321\200\320\276\321\207\320\270\321\202\320\260\320\275\320\275\320\276\320\271 \320\273\320\270\321\202\320\265\321\200\320\260\321\202\321\203\321\200\321\213", nullptr));
        label_title->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270:", nullptr));
        label_category->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217 (\320\266\320\260\320\275\321\200):", nullptr));
        comboBox_category->setItemText(0, QCoreApplication::translate("MainWindow", "\320\244\320\260\320\275\321\202\320\260\321\201\321\202\320\270\320\272\320\260", nullptr));
        comboBox_category->setItemText(1, QCoreApplication::translate("MainWindow", "\320\244\321\215\320\275\321\202\320\265\320\267\320\270", nullptr));
        comboBox_category->setItemText(2, QCoreApplication::translate("MainWindow", "\320\224\320\265\321\202\320\265\320\272\321\202\320\270\320\262", nullptr));
        comboBox_category->setItemText(3, QCoreApplication::translate("MainWindow", "\320\240\320\276\320\274\320\260\320\275", nullptr));
        comboBox_category->setItemText(4, QCoreApplication::translate("MainWindow", "\320\235\320\260\321\203\321\207\320\275\320\260\321\217 \320\273\320\270\321\202\320\265\321\200\320\260\321\202\321\203\321\200\320\260", nullptr));
        comboBox_category->setItemText(5, QCoreApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217", nullptr));
        comboBox_category->setItemText(6, QCoreApplication::translate("MainWindow", "\320\221\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\217", nullptr));
        comboBox_category->setItemText(7, QCoreApplication::translate("MainWindow", "\320\237\320\276\321\215\320\267\320\270\321\217", nullptr));
        comboBox_category->setItemText(8, QCoreApplication::translate("MainWindow", "\320\242\321\200\320\270\320\273\320\273\320\265\321\200", nullptr));
        comboBox_category->setItemText(9, QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));

        label_rating->setText(QCoreApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\260:", nullptr));
        label_author->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200:", nullptr));
        label_date->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\275\320\260\320\277\320\270\321\201\320\260\320\275\320\270\321\217:", nullptr));
        label_difficulty->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214:", nullptr));
        comboBox_difficulty->setItemText(0, QCoreApplication::translate("MainWindow", "\320\233\320\265\320\263\320\272\320\260\321\217", nullptr));
        comboBox_difficulty->setItemText(1, QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217", nullptr));
        comboBox_difficulty->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\320\273\320\276\320\266\320\275\320\260\321\217", nullptr));

        tableWidget_books->setProperty("horizontalHeaderLabels", QVariant(QStringList{
            QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr),
            QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr),
            QCoreApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\260", nullptr),
            QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200", nullptr),
            QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr),
            QCoreApplication::translate("MainWindow", "\320\241\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214", nullptr),
            QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr)}));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        pushButton_recommend->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\200\320\265\320\272\320\276\320\274\320\265\320\275\320\264\320\260\321\206\320\270\321\216", nullptr));
        pushButton_checked->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\265\321\202\320\270\321\202\321\214 \320\277\321\200\320\276\321\207\320\270\321\202\320\260\320\275\320\275\321\213\320\274", nullptr));
        pushButton_export->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202 \321\201\320\277\320\270\321\201\320\272\320\260", nullptr));
        pushButton_import->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\320\277\320\276\321\200\321\202 \321\201\320\277\320\270\321\201\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
