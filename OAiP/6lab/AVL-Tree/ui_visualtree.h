/********************************************************************************
** Form generated from reading UI file 'visualtree.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALTREE_H
#define UI_VISUALTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualTree
{
public:

    void setupUi(QWidget *VisualTree)
    {
        if (VisualTree->objectName().isEmpty())
            VisualTree->setObjectName(QStringLiteral("VisualTree"));
        VisualTree->resize(2000, 1000);

        retranslateUi(VisualTree);

        QMetaObject::connectSlotsByName(VisualTree);
    } // setupUi

    void retranslateUi(QWidget *VisualTree)
    {
        VisualTree->setWindowTitle(QApplication::translate("VisualTree", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VisualTree: public Ui_VisualTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALTREE_H
