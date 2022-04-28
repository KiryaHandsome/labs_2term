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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *Add_ValueEdit;
    QLineEdit *Add_KeyEdit;
    QPushButton *RemoveButton;
    QPushButton *SearchButton;
    QLineEdit *SearchEdit;
    QPushButton *AddButton;
    QLineEdit *RemoveEdit;
    QPushButton *Create2TablesButton;
    QRadioButton *LeftTableButton;
    QRadioButton *RightTableButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget_1;
    QTableWidget *tableWidget_2;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1023, 675);
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(120, 380, 804, 192));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Add_ValueEdit = new QLineEdit(gridLayoutWidget);
        Add_ValueEdit->setObjectName(QStringLiteral("Add_ValueEdit"));
        Add_ValueEdit->setMaxLength(9);

        gridLayout_2->addWidget(Add_ValueEdit, 4, 0, 1, 1);

        Add_KeyEdit = new QLineEdit(gridLayoutWidget);
        Add_KeyEdit->setObjectName(QStringLiteral("Add_KeyEdit"));
        Add_KeyEdit->setMaxLength(9);

        gridLayout_2->addWidget(Add_KeyEdit, 2, 0, 1, 1);

        RemoveButton = new QPushButton(gridLayoutWidget);
        RemoveButton->setObjectName(QStringLiteral("RemoveButton"));

        gridLayout_2->addWidget(RemoveButton, 1, 1, 1, 1);

        SearchButton = new QPushButton(gridLayoutWidget);
        SearchButton->setObjectName(QStringLiteral("SearchButton"));

        gridLayout_2->addWidget(SearchButton, 1, 2, 1, 1);

        SearchEdit = new QLineEdit(gridLayoutWidget);
        SearchEdit->setObjectName(QStringLiteral("SearchEdit"));
        SearchEdit->setMaxLength(9);

        gridLayout_2->addWidget(SearchEdit, 2, 2, 1, 1);

        AddButton = new QPushButton(gridLayoutWidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        gridLayout_2->addWidget(AddButton, 1, 0, 1, 1);

        RemoveEdit = new QLineEdit(gridLayoutWidget);
        RemoveEdit->setObjectName(QStringLiteral("RemoveEdit"));
        RemoveEdit->setMaxLength(9);

        gridLayout_2->addWidget(RemoveEdit, 2, 1, 1, 1);

        Create2TablesButton = new QPushButton(gridLayoutWidget);
        Create2TablesButton->setObjectName(QStringLiteral("Create2TablesButton"));

        gridLayout_2->addWidget(Create2TablesButton, 0, 0, 1, 3);

        LeftTableButton = new QRadioButton(gridLayoutWidget);
        LeftTableButton->setObjectName(QStringLiteral("LeftTableButton"));

        gridLayout_2->addWidget(LeftTableButton, 4, 1, 1, 1);

        RightTableButton = new QRadioButton(gridLayoutWidget);
        RightTableButton->setObjectName(QStringLiteral("RightTableButton"));

        gridLayout_2->addWidget(RightTableButton, 4, 2, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 40, 961, 331));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget_1 = new QTableWidget(widget);
        if (tableWidget_1->columnCount() < 2)
            tableWidget_1->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_1->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_1->setObjectName(QStringLiteral("tableWidget_1"));
        tableWidget_1->setFont(font);

        horizontalLayout->addWidget(tableWidget_1);

        tableWidget_2 = new QTableWidget(widget);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setFont(font);

        horizontalLayout->addWidget(tableWidget_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1023, 29));
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
        Add_ValueEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        Add_KeyEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        RemoveButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        SearchButton->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\272\320\260\321\202\321\214", Q_NULLPTR));
        SearchEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        AddButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 ", Q_NULLPTR));
        RemoveEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        Create2TablesButton->setText(QApplication::translate("MainWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 2 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 \321\201 \320\272\320\273\321\216\321\207\320\260\320\274\320\270 \321\200\320\260\320\267\320\275\321\213\321\205 \320\267\320\275\320\260\320\272\320\276\320\262", Q_NULLPTR));
        LeftTableButton->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\262\320\260\321\217 \321\202\320\260\320\261\320\273\320\270\321\206\320\260", Q_NULLPTR));
        RightTableButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\260\321\217 \321\202\320\260\320\261\320\273\320\270\321\206\320\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
