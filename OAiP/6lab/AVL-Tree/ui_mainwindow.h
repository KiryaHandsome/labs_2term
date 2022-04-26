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
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox;
    QPushButton *AddButton;
    QLineEdit *FindEdit;
    QPushButton *DeleteButton;
    QPushButton *FindButton;
    QPushButton *PrintButton;
    QPushButton *VisualizationButton;
    QGridLayout *gridLayout_2;
    QLineEdit *Add_KeyEdit;
    QLineEdit *Add_InfoEdit;
    QLineEdit *DeleteEdit;
    QPushButton *NumOfNodesButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *arrayWidget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *ClearButton;
    QPushButton *AddCellButton;
    QPushButton *InputButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1011, 651);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 0, 921, 431));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(layoutWidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QFont font1;
        font1.setPointSize(11);
        tableWidget->setFont(font1);

        horizontalLayout->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font1);

        gridLayout_3->addWidget(comboBox, 3, 2, 1, 1);

        AddButton = new QPushButton(layoutWidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setFont(font1);

        gridLayout_3->addWidget(AddButton, 4, 1, 1, 1);

        FindEdit = new QLineEdit(layoutWidget);
        FindEdit->setObjectName(QStringLiteral("FindEdit"));
        FindEdit->setFont(font1);
        FindEdit->setMaxLength(9);

        gridLayout_3->addWidget(FindEdit, 1, 2, 1, 1);

        DeleteButton = new QPushButton(layoutWidget);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));
        DeleteButton->setFont(font1);

        gridLayout_3->addWidget(DeleteButton, 2, 1, 1, 1);

        FindButton = new QPushButton(layoutWidget);
        FindButton->setObjectName(QStringLiteral("FindButton"));
        FindButton->setFont(font1);

        gridLayout_3->addWidget(FindButton, 1, 1, 1, 1);

        PrintButton = new QPushButton(layoutWidget);
        PrintButton->setObjectName(QStringLiteral("PrintButton"));
        PrintButton->setFont(font1);

        gridLayout_3->addWidget(PrintButton, 3, 1, 1, 1);

        VisualizationButton = new QPushButton(layoutWidget);
        VisualizationButton->setObjectName(QStringLiteral("VisualizationButton"));
        VisualizationButton->setFont(font1);

        gridLayout_3->addWidget(VisualizationButton, 6, 1, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Add_KeyEdit = new QLineEdit(layoutWidget);
        Add_KeyEdit->setObjectName(QStringLiteral("Add_KeyEdit"));
        Add_KeyEdit->setFont(font1);
        Add_KeyEdit->setStyleSheet(QStringLiteral(""));
        Add_KeyEdit->setMaxLength(9);

        gridLayout_2->addWidget(Add_KeyEdit, 0, 1, 1, 1);

        Add_InfoEdit = new QLineEdit(layoutWidget);
        Add_InfoEdit->setObjectName(QStringLiteral("Add_InfoEdit"));
        Add_InfoEdit->setFont(font1);
        Add_InfoEdit->setMaxLength(15);

        gridLayout_2->addWidget(Add_InfoEdit, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 4, 2, 1, 1);

        DeleteEdit = new QLineEdit(layoutWidget);
        DeleteEdit->setObjectName(QStringLiteral("DeleteEdit"));
        DeleteEdit->setFont(font1);
        DeleteEdit->setMaxLength(9);

        gridLayout_3->addWidget(DeleteEdit, 2, 2, 1, 1);

        NumOfNodesButton = new QPushButton(layoutWidget);
        NumOfNodesButton->setObjectName(QStringLiteral("NumOfNodesButton"));
        NumOfNodesButton->setFont(font1);

        gridLayout_3->addWidget(NumOfNodesButton, 5, 1, 1, 2);


        verticalLayout->addLayout(gridLayout_3);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(72, 440, 921, 161));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        arrayWidget = new QTableWidget(layoutWidget1);
        if (arrayWidget->rowCount() < 2)
            arrayWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        arrayWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        arrayWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        arrayWidget->setObjectName(QStringLiteral("arrayWidget"));
        arrayWidget->setFont(font1);

        horizontalLayout_2->addWidget(arrayWidget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        ClearButton = new QPushButton(layoutWidget1);
        ClearButton->setObjectName(QStringLiteral("ClearButton"));
        ClearButton->setFont(font1);

        verticalLayout_4->addWidget(ClearButton);

        AddCellButton = new QPushButton(layoutWidget1);
        AddCellButton->setObjectName(QStringLiteral("AddCellButton"));
        AddCellButton->setFont(font1);

        verticalLayout_4->addWidget(AddCellButton);

        InputButton = new QPushButton(layoutWidget1);
        InputButton->setObjectName(QStringLiteral("InputButton"));
        InputButton->setFont(font1);

        verticalLayout_4->addWidget(InputButton);


        horizontalLayout_2->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1011, 25));
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
        label->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\264\320\273\321\217 \321\200\320\260\320\261\320\276\321\202\321\213 \321\201 \320\220\320\222\320\233 \320\264\320\265\321\200\320\265\320\262\320\276\320\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\222 \320\277\321\200\321\217\320\274\320\276\320\274 \320\277\320\276\321\200\321\217\320\264\320\272\320\265", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\222 \320\276\320\261\321\200\320\260\321\202\320\275\320\276\320\274 \320\277\320\276\321\200\321\217\320\264\320\272\320\265", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\237\320\276 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216 \320\272\320\273\321\216\321\207\320\260", Q_NULLPTR)
        );
        AddButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", Q_NULLPTR));
        FindEdit->setText(QString());
        FindEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        DeleteButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276 \320\272\320\273\321\216\321\207\321\203", Q_NULLPTR));
        FindButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\277\320\276 \320\272\320\273\321\216\321\207\321\203", Q_NULLPTR));
        PrintButton->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216", Q_NULLPTR));
        VisualizationButton->setText(QApplication::translate("MainWindow", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\264\320\265\321\200\320\265\320\262\320\260", Q_NULLPTR));
        Add_KeyEdit->setText(QString());
        Add_KeyEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        Add_InfoEdit->setText(QString());
        Add_InfoEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", Q_NULLPTR));
        DeleteEdit->setText(QString());
        DeleteEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        NumOfNodesButton->setText(QApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \321\203\320\267\320\273\320\276\320\262 \321\201 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\217\320\274\320\270 \320\275\320\260 \320\276\320\264\320\275\321\203 \320\262\320\265\321\202\320\262\321\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = arrayWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = arrayWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", Q_NULLPTR));
        ClearButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\274\320\260\321\201\321\201\320\270\320\262", Q_NULLPTR));
        AddCellButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\217\321\207\320\265\320\271\320\272\321\203 \320\262 \320\274\320\260\321\201\321\201\320\270\320\262", Q_NULLPTR));
        InputButton->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\264\320\260\320\275\320\275\321\213\320\265 \320\270\320\267 \320\274\320\260\321\201\321\201\320\270\320\262\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
