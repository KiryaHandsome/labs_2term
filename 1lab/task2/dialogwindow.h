#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include "figure.h"
#include <QDialog>


namespace Ui {
class DialogWindow;
}

class DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWindow(QWidget *parent = nullptr);
    ~DialogWindow();
    Ui::DialogWindow *ui;

    void setLabelText(Figure* object);
    void setNewSize(int num1, int num2, int num3);

private:
    Figure* currentFigure = nullptr;

private slots:
    void enterButton_clicked();
};


#endif // DIALOGWINDOW_H
