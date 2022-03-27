#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include <QDialog>
#include "list.h"

namespace Ui {
class DialogWindow;
}

class DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWindow(QWidget *parent = nullptr);
    ~DialogWindow();

    void setSizeOfList(int);
    void setLabelText(QString);

private slots:
    void enterButton_clicked();

signals:
    void addCall(Call, int);
    void changeCall(Call, int);

private:
    Ui::DialogWindow *ui;
    int sizeOfList;
};

#endif // DIALOGWINDOW_H
