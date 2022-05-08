/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *insert_KeyEdit;
    QLineEdit *rehashEdit;
    QLineEdit *find_Edit;
    QPushButton *eraseButton;
    QPushButton *insertButton;
    QPushButton *rehashButton;
    QPushButton *containsButton;
    QLineEdit *erase_Edit;
    QPushButton *findButton;
    QLineEdit *insert_ValueEdit;
    QLineEdit *containsEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(877, 602);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(360, 20, 471, 501));
        QFont font;
        font.setPointSize(11);
        tableWidget->setFont(font);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 70, 261, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        insert_KeyEdit = new QLineEdit(gridLayoutWidget);
        insert_KeyEdit->setObjectName(QStringLiteral("insert_KeyEdit"));
        insert_KeyEdit->setFont(font);
        insert_KeyEdit->setMaxLength(9);

        gridLayout->addWidget(insert_KeyEdit, 0, 1, 1, 1);

        rehashEdit = new QLineEdit(gridLayoutWidget);
        rehashEdit->setObjectName(QStringLiteral("rehashEdit"));
        rehashEdit->setFont(font);
        rehashEdit->setMaxLength(4);

        gridLayout->addWidget(rehashEdit, 4, 1, 1, 1);

        find_Edit = new QLineEdit(gridLayoutWidget);
        find_Edit->setObjectName(QStringLiteral("find_Edit"));
        find_Edit->setFont(font);
        find_Edit->setMaxLength(9);

        gridLayout->addWidget(find_Edit, 2, 1, 1, 1);

        eraseButton = new QPushButton(gridLayoutWidget);
        eraseButton->setObjectName(QStringLiteral("eraseButton"));
        eraseButton->setFont(font);

        gridLayout->addWidget(eraseButton, 3, 0, 1, 1);

        insertButton = new QPushButton(gridLayoutWidget);
        insertButton->setObjectName(QStringLiteral("insertButton"));
        insertButton->setFont(font);

        gridLayout->addWidget(insertButton, 0, 0, 1, 1);

        rehashButton = new QPushButton(gridLayoutWidget);
        rehashButton->setObjectName(QStringLiteral("rehashButton"));
        rehashButton->setFont(font);

        gridLayout->addWidget(rehashButton, 4, 0, 1, 1);

        containsButton = new QPushButton(gridLayoutWidget);
        containsButton->setObjectName(QStringLiteral("containsButton"));
        containsButton->setFont(font);

        gridLayout->addWidget(containsButton, 5, 0, 1, 1);

        erase_Edit = new QLineEdit(gridLayoutWidget);
        erase_Edit->setObjectName(QStringLiteral("erase_Edit"));
        erase_Edit->setFont(font);
        erase_Edit->setMaxLength(9);

        gridLayout->addWidget(erase_Edit, 3, 1, 1, 1);

        findButton = new QPushButton(gridLayoutWidget);
        findButton->setObjectName(QStringLiteral("findButton"));
        findButton->setFont(font);

        gridLayout->addWidget(findButton, 2, 0, 1, 1);

        insert_ValueEdit = new QLineEdit(gridLayoutWidget);
        insert_ValueEdit->setObjectName(QStringLiteral("insert_ValueEdit"));
        insert_ValueEdit->setFont(font);

        gridLayout->addWidget(insert_ValueEdit, 1, 1, 1, 1);

        containsEdit = new QLineEdit(gridLayoutWidget);
        containsEdit->setObjectName(QStringLiteral("containsEdit"));
        containsEdit->setFont(font);
        containsEdit->setMaxLength(4);

        gridLayout->addWidget(containsEdit, 5, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 877, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Key", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Value", Q_NULLPTR));
        insert_KeyEdit->setPlaceholderText(QApplication::translate("MainWindow", "Key...(int)", Q_NULLPTR));
        rehashEdit->setPlaceholderText(QApplication::translate("MainWindow", "count...(int)", Q_NULLPTR));
        find_Edit->setPlaceholderText(QApplication::translate("MainWindow", "Key...(int)", Q_NULLPTR));
        eraseButton->setText(QApplication::translate("MainWindow", "erase", Q_NULLPTR));
        insertButton->setText(QApplication::translate("MainWindow", "insert", Q_NULLPTR));
        rehashButton->setText(QApplication::translate("MainWindow", "rehash", Q_NULLPTR));
        containsButton->setText(QApplication::translate("MainWindow", "contains", Q_NULLPTR));
        erase_Edit->setPlaceholderText(QApplication::translate("MainWindow", "Key...int()", Q_NULLPTR));
        findButton->setText(QApplication::translate("MainWindow", "find", Q_NULLPTR));
        insert_ValueEdit->setPlaceholderText(QApplication::translate("MainWindow", "Value...(int)", Q_NULLPTR));
        containsEdit->setPlaceholderText(QApplication::translate("MainWindow", "Key...(int)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
