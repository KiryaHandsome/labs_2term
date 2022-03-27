#include "entrance.h"
#include "ui_entrance.h"

Entrance::Entrance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Entrance)
{
    ui->setupUi(this);

    connect(ui->chooseFileButton, SIGNAL(clicked()), this, SLOT(chooseFileButton_clicked()));
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(okButton_clicked()));
}

Entrance::~Entrance()
{
    delete ui;
}

void Entrance::okButton_clicked()
{
    emit ok();
}
void Entrance::chooseFileButton_clicked()
{
    emit file();
}

