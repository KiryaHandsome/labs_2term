#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <List.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setSizeOfList(int);
    void setLabelText(QString);
private slots:
    void enterButton_clicked();

signals:
    void addBook(Book, int);
    void changeBook(Book, int);

private:
    Ui::Dialog *ui;
    int sizeOfList;

};

#endif // DIALOG_H
