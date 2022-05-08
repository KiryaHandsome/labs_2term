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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *mapButton;
    QRadioButton *setButton;
    QRadioButton *bitsetButton;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *keyEdit;
    QLineEdit *valueEdit;
    QLineEdit *positionEdit;
    QLineEdit *valueBoolEdit;
    QPushButton *enterButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(974, 594);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 20, 801, 32));
        QFont font;
        font.setPointSize(11);
        layoutWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mapButton = new QRadioButton(layoutWidget);
        mapButton->setObjectName(QStringLiteral("mapButton"));
        mapButton->setFont(font);

        horizontalLayout->addWidget(mapButton);

        setButton = new QRadioButton(layoutWidget);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setFont(font);

        horizontalLayout->addWidget(setButton);

        bitsetButton = new QRadioButton(layoutWidget);
        bitsetButton->setObjectName(QStringLiteral("bitsetButton"));
        bitsetButton->setFont(font);

        horizontalLayout->addWidget(bitsetButton);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(370, 60, 511, 341));
        textBrowser->setFont(font);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(75, 60, 291, 232));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font);

        verticalLayout_2->addWidget(comboBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        keyEdit = new QLineEdit(layoutWidget1);
        keyEdit->setObjectName(QStringLiteral("keyEdit"));
        keyEdit->setFont(font);
        keyEdit->setMaxLength(9);

        verticalLayout->addWidget(keyEdit);

        valueEdit = new QLineEdit(layoutWidget1);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));
        valueEdit->setFont(font);
        valueEdit->setMaxLength(20);

        verticalLayout->addWidget(valueEdit);

        positionEdit = new QLineEdit(layoutWidget1);
        positionEdit->setObjectName(QStringLiteral("positionEdit"));
        positionEdit->setFont(font);
        positionEdit->setMaxLength(9);

        verticalLayout->addWidget(positionEdit);

        valueBoolEdit = new QLineEdit(layoutWidget1);
        valueBoolEdit->setObjectName(QStringLiteral("valueBoolEdit"));
        valueBoolEdit->setFont(font);
        valueBoolEdit->setMaxLength(1);

        verticalLayout->addWidget(valueBoolEdit);

        enterButton = new QPushButton(layoutWidget1);
        enterButton->setObjectName(QStringLiteral("enterButton"));
        enterButton->setFont(font);

        verticalLayout->addWidget(enterButton);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 974, 25));
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
        mapButton->setText(QApplication::translate("MainWindow", "Map", Q_NULLPTR));
        setButton->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        bitsetButton->setText(QApplication::translate("MainWindow", "Bitset", Q_NULLPTR));
        keyEdit->setPlaceholderText(QApplication::translate("MainWindow", "Key...(int)", Q_NULLPTR));
        valueEdit->setPlaceholderText(QApplication::translate("MainWindow", "Value...(string)", Q_NULLPTR));
        positionEdit->setPlaceholderText(QApplication::translate("MainWindow", "Position...(size_t)", Q_NULLPTR));
        valueBoolEdit->setPlaceholderText(QApplication::translate("MainWindow", "Value...(bool: 1- true, 0 - false)", Q_NULLPTR));
        enterButton->setText(QApplication::translate("MainWindow", "Enter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
