#include "rectangle.h"
#include "./ui_rectangle.h"
#include <QLabel>
#include <QKeyEvent>
#include <QTransform>
#include <QPalette>



Rectangle::Rectangle(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Rectangle)
{
    ui->setupUi(this);
    label = new QLabel(this);
    image = new QPixmap(":/body.png");
    label->setPixmap(*image);
    label->show();
    label->setGeometry(300, 132, 360, 300);
    x = 300; y = 132;

    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);  //move pixmap to right bottom

    /*background = new QLabel(this);
    background->setGeometry(50, 150, 1400, 600);
    QPixmap fon(":/townRoad");
    fon.scaled(1400, 600);
    background->setPixmap(fon);
    //background->show();
    background->lower();*/

    QPixmap my_background(":/townRoad");
    my_background = my_background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, my_background);
    this->setPalette(palette);

    //ui->centralwidget->setStyleSheet("background-color: transparent");

}

Rectangle::~Rectangle()
{
    delete label;
    delete image;
    delete ui;
}

void Rectangle::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Left){
        if(x < 0){
            label->setGeometry(ui->centralwidget->width(), y, label->width(), label->height());
            x = ui->centralwidget->width();
        } else {
            label->setGeometry(x - 5, y, label->width(), label->height());
            x -= 5;
        }
    }
    if(event->key() == Qt::Key_Right){
        label->setGeometry((x + 5) % ui->centralwidget->width(), y, label->width(), label->height());
        x = (x + 5) % ui->centralwidget->width();
    }
}

Truck::Truck()
{
    chassis = new QLabel(this);
    wheel1 = new QLabel(this);
    wheel2 = new QLabel(this);

    wheelImage = new QPixmap(":/wheel.png");

    chassis->setGeometry(x + 110, y + 135, 400, 300);
    chassis->setPixmap(static_cast<QPixmap>(":/chassis.png"));

    wheel1->setGeometry(x + 165, y + 350, wheelImage->width(), wheelImage->height());
    wheel1->setPixmap(static_cast<QPixmap>(":/wheel.png"));

    wheel2->setGeometry(x + 380, y + 350, wheelImage->width(), wheelImage->height());
    wheel2->setPixmap(static_cast<QPixmap>(":/wheel.png"));

    wheel1->setAlignment(Qt::AlignCenter);
    wheel2->setAlignment(Qt::AlignCenter);

    label->raise();     //move body to foreground
}

void Truck::keyPressEvent(QKeyEvent* event)
{
    switch(event->key()){
    case Qt::Key_Left:      //move left
        if(x < -400){
            chassis->setGeometry(ui->centralwidget->width() + 110, y + 135, chassis->width(), chassis->height());
            label->setGeometry(ui->centralwidget->width(), y, label->width(), label->height());

            wheel1->setGeometry(x + 165 - 5, y + 350, wheel1->width(), wheel2->height());
            wheel1->setGeometry(x + 380 - 5, y + 350, wheel1->width(), wheel2->height());

            x = ui->centralwidget->width() - 110;
        } else {
            chassis->setGeometry(x + 110 - 5 , y + 135, chassis->width(), chassis->height());
            label->setGeometry(x - 5, y, label->width(), label->height());

            wheel1->setGeometry(x + 165 - 5, y + 350, wheel1->width(), wheel1->height());
            wheel2->setGeometry(x + 380 - 5, y + 350, wheel2->width(), wheel2->height());

            QTransform* trans = new QTransform;
            wheelAngle -= 4;
            trans->rotate(wheelAngle);
            wheel1->setPixmap(wheelImage->transformed(*trans));     //rotate wheels
            wheel2->setPixmap(wheelImage->transformed(*trans));
            delete trans;

            x -= 5;
        }
        break;
    case Qt::Key_Right:     //move right
        if(x > ui->centralwidget->width() - 150){
            chassis->setGeometry(-200, y + 135, chassis->width(), chassis->height());
            label->setGeometry(-310, y, label->width(), label->height());

            wheel1->setGeometry(x + 165 - 5, y + 350, wheel1->width(), wheel1->height());
            wheel2->setGeometry(x + 380 - 5, y + 350, wheel2->width(), wheel2->height());

            x = -310;
        } else {
            chassis->setGeometry((x + 110 + 5) % ui->centralwidget->width(), y + 135, chassis->width(), chassis->height());
            label->setGeometry((x + 5) % ui->centralwidget->width(), y, label->width(), label->height());

            wheel1->setGeometry(x + 165 + 5, y + 350, wheel1->width(), wheel1->height());
            wheel2->setGeometry(x + 380 + 5, y + 350, wheel2->width(), wheel2->height());

            QTransform* trans = new QTransform;
            wheelAngle += 4;
            trans->rotate(wheelAngle);
            wheel1->setPixmap(wheelImage->transformed(*trans)); //rotate wheels
            wheel2->setPixmap(wheelImage->transformed(*trans));
            delete trans;

            x = (x + 5) % ui->centralwidget->width();
        }
        break;
    case Qt::Key_Up:        //body up
        if(angle > -35){
            QTransform* trans = new QTransform;
            trans->rotate(--angle);
            label->setPixmap(image->transformed(*trans));
            delete trans;
        }
        break;
    case Qt::Key_Down:      //body down
        if(angle < 0){
            QTransform* trans = new QTransform;
            trans->rotate(++angle);
            label->setPixmap(image->transformed(*trans));
            delete trans;
        }
        break;
    }
}
Truck::~Truck()
{
    delete wheelImage;
    delete wheel1;
    delete wheel2;
    delete chassis;
}



