#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QComboBox>
#include "date.h"



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void setLabelText(QString text);

    void setCurrentRow(int row);

    void setTableWidget(QTableWidget* widget);

    void setComboBox(QComboBox* box);

    void setFileName(QString fileName);


private slots:
    void enterButton_clicked();

private:
    Ui::Dialog *ui;
    QTableWidget* widget;
    QComboBox* box;
    int row; //contain number of current row
    QString fileName;
};

#endif // DIALOG_H
