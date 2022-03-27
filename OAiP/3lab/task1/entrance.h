#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <QDialog>

namespace Ui {
class Entrance;
}

class Entrance : public QDialog
{
    Q_OBJECT

public:
    explicit Entrance(QWidget *parent = nullptr);
    ~Entrance();

private slots:
    void okButton_clicked();
    void chooseFileButton_clicked();

signals:
    void ok();
    void file();

private:
    Ui::Entrance *ui;
};

#endif // ENTRANCE_H
