#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QTimer>
#include <QPointF>
#include <QKeyEvent>
#include <QDialog>
#include <QLineEdit>
#include <QChar>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->circleButton, SIGNAL(clicked()), this, SLOT(circleButton_clicked()));
    connect(ui->rhombButton, SIGNAL(clicked()), this, SLOT(rhombButton_clicked()));
    connect(ui->rectangleButton, SIGNAL(clicked()), this, SLOT(rectangleButton_clicked()));
    connect(ui->triangleButton, SIGNAL(clicked()), this, SLOT(triangleButton_clicked()));
    connect(ui->squareButton, SIGNAL(clicked()), this, SLOT(squareButton_clicked()));
    connect(ui->ellipseButton, SIGNAL(clicked()), this, SLOT(ellipseButton_clicked()));
    connect(ui->fivePButton, SIGNAL(clicked()), this, SLOT(fivePButton_clicked()));
    connect(ui->sixPButton, SIGNAL(clicked()), this, SLOT(sixPButton_clicked()));
    connect(ui->eightPButton, SIGNAL(clicked()), this, SLOT(eightPButton_clicked()));
    connect(ui->hexagonButton, SIGNAL(clicked()), this, SLOT(hexagonButton_clicked()));
    connect(ui->parallButton, SIGNAL(clicked()), this, SLOT(parallButton_clicked()));

    timer = new QTimer[8];
    for(int i = 0; i < 8; i++) timer[i].setParent(this);

    connect(&timer[Move::moveLeft], SIGNAL(timeout()), this, SLOT(moveLeftButton_pressed()));
    connect(&timer[Move::moveRight], SIGNAL(timeout()), this, SLOT(moveRightButton_pressed()));
    connect(&timer[Move::moveUp], SIGNAL(timeout()), this, SLOT(moveUpButton_pressed()));
    connect(&timer[Move::moveDown], SIGNAL(timeout()), this, SLOT(moveDownButton_pressed()));
    connect(&timer[Move::zoomOut], SIGNAL(timeout()), this, SLOT(zoomOutButton_pressed()));
    connect(&timer[Move::zoomIn], SIGNAL(timeout()), this, SLOT(zoomInButton_pressed()));
    connect(&timer[Move::rotateRight], SIGNAL(timeout()), this, SLOT(rotateRightButton_pressed()));
    connect(&timer[Move::rotateLeft], SIGNAL(timeout()), this, SLOT(rotateLeftButton_pressed()));

    connect(ui->zoomInButton, SIGNAL(released()), this, SLOT(zoomInButton_released()));
    connect(ui->zoomOutButton, SIGNAL(released()), this, SLOT(zoomOutButton_released()));
    connect(ui->zoomInButton, SIGNAL(pressed()), this, SLOT(zoomInButton_pressed()));
    connect(ui->zoomOutButton, SIGNAL(pressed()), this, SLOT(zoomOutButton_pressed()));

    connect(ui->rotateLeftButton, SIGNAL(released()), this, SLOT(rotateLeftButton_released()));
    connect(ui->rotateRightButton, SIGNAL(released()), this, SLOT(rotateRightButton_released()));
    connect(ui->rotateLeftButton, SIGNAL(pressed()), this, SLOT(rotateLeftButton_pressed()));
    connect(ui->rotateRightButton, SIGNAL(pressed()), this, SLOT(rotateRightButton_pressed()));

    connect(ui->moveRightButton, SIGNAL(pressed()), this, SLOT(moveRightButton_pressed()));
    connect(ui->moveLeftButton, SIGNAL(pressed()), this, SLOT(moveLeftButton_pressed()));
    connect(ui->moveUpButton, SIGNAL(pressed()), this, SLOT(moveUpButton_pressed()));
    connect(ui->moveDownButton, SIGNAL(pressed()), this, SLOT(moveDownButton_pressed()));

    connect(ui->moveRightButton, SIGNAL(released()), this, SLOT(moveRightButton_released()));
    connect(ui->moveLeftButton, SIGNAL(released()), this, SLOT(moveLeftButton_released()));
    connect(ui->moveUpButton, SIGNAL(released()), this, SLOT(moveUpButton_released()));
    connect(ui->moveDownButton, SIGNAL(released()), this, SLOT(moveDownButton_released()));

    connect(ui->areaButton, SIGNAL(clicked()), this, SLOT(areaButton_clicked()));
    connect(ui->perimeterButton, SIGNAL(clicked()), this, SLOT(perimeterButton_clicked()));
    connect(ui->centerMassButton, SIGNAL(clicked()), this, SLOT(centerMassButton_clicked()));
    connect(ui->changeSizeButton, SIGNAL(clicked()), this, SLOT(changeSizeButton_clicked()));
}

MainWindow::~MainWindow()
{

    delete [] timer;
    if(object != nullptr) delete object;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.translate(350, 250);

    if(object){
        painter.setClipRect(-350, -250, 690, 470);
        painter.scale(object->getZoom(), object->getZoom());
        painter.rotate(object->getAngle());
        object->draw(&painter);
    }
}

void MainWindow::moveLeftButton_released()
{
    timer[Move::moveLeft].stop();
}
void MainWindow::moveRightButton_released()
{
    timer[Move::moveRight].stop();
}

void MainWindow::moveUpButton_released()
{
    timer[Move::moveUp].stop();
}

void MainWindow::moveDownButton_released()
{
    timer[Move::moveDown].stop();
}

void MainWindow::moveLeftButton_pressed()
{
    timer[Move::moveLeft].start(10);
    if(object && object->getCenter().x() > -300 / object->getZoom()){
        int x = object->getCenter().x();
        int y = object->getCenter().y();
        object->setCenter(QPoint(x - 1, y));
    }
    repaint();
}
void MainWindow::moveRightButton_pressed()
{
    timer[Move::moveRight].start(10);
    if(object && object->getCenter().x() < 200/ object->getZoom()){
        int x = object->getCenter().x();
        int y = object->getCenter().y();
        object->setCenter(QPoint(x + 1, y));
    }
    repaint();
}
void MainWindow::moveUpButton_pressed()
{
    timer[Move::moveUp].start(10);
    if(object && object->getCenter().y() > -200/ object->getZoom()){
        int x = object->getCenter().x();
        int y = object->getCenter().y();
        object->setCenter(QPoint(x, y - 1));
    }
    repaint();
}
void MainWindow::moveDownButton_pressed()
{
    timer[Move::moveDown].start(10);
    if(object && object->getCenter().y() < 200/ object->getZoom()){
        int x = object->getCenter().x();
        int y = object->getCenter().y();
        object->setCenter(QPoint(x, y + 1));
    }
    repaint();
}

void MainWindow::circleButton_clicked()
{
    if(object) delete object;
    object = new Circle();
    repaint();
}

void MainWindow::squareButton_clicked()
{
    if(object) delete object;
    object = new Square();
    repaint();
}

void MainWindow::triangleButton_clicked()
{
    if(object) delete object;
    object = new Triangle();
    repaint();
}

void MainWindow::rectangleButton_clicked()
{
    if(object) delete object;
    object = new class Rectangle();
    repaint();
}

void MainWindow::rhombButton_clicked()
{
    if(object) delete object;
    object = new Rhomb();
    repaint();
}

void MainWindow::fivePButton_clicked()
{
    if(object) delete object;
    object = new FivePointedStar();
    repaint();
}

void MainWindow::sixPButton_clicked()
{
    if(object) delete object;
    object = new SixPointedStar();
    repaint();
}

void MainWindow::eightPButton_clicked()
{
    if(object) delete object;
    object = new EightPointedStar();
    repaint();
}

void MainWindow::hexagonButton_clicked()
{
    if(object) delete object;
    object = new Hexagon();
    repaint();
}

void MainWindow::ellipseButton_clicked()
{
    if(object) delete object;
    object = new Ellipse();
    repaint();
}

void MainWindow::parallButton_clicked()
{
    if(object) delete object;
    object = new Parallelogram();
    repaint();
}

void MainWindow::zoomInButton_pressed()
{
    timer[Move::zoomIn].start(50);
    if(object && (object->getZoom() < 2) && (object->getZoom() < 2)){
        object->setZoom(object->getZoom() + 0.1);
    }
    repaint();
}

void MainWindow::zoomOutButton_pressed()
{
    timer[Move::zoomOut].start(50);
    if(object && (object->getZoom() > 0.5) && (object->getZoom() > 0.5)){
        object->setZoom(object->getZoom() - 0.1);
    }
    repaint();
}

void MainWindow::rotateLeftButton_pressed()
{
    timer[Move::rotateLeft].start(50);
    if(object) object->setAngle(object->getAngle() - 5);
    repaint();
}

void MainWindow::rotateRightButton_pressed()
{
    timer[Move::rotateRight].start(50);
    if(object) object->setAngle(object->getAngle() + 5);
    repaint();
}

void MainWindow::rotateRightButton_released(){ timer[Move::rotateRight].stop(); }
void MainWindow::rotateLeftButton_released(){ timer[Move::rotateLeft].stop(); }
void MainWindow::zoomOutButton_released(){ timer[Move::zoomOut].stop(); }
void MainWindow::zoomInButton_released(){ timer[Move::zoomIn].stop(); }

void MainWindow::areaButton_clicked()
{
    if(object){
        QString result = QString::number(object->area());

        ui->statusbar->showMessage(result);
    }
}

void MainWindow::perimeterButton_clicked()
{
    if(object){
        QString result = QString::number(object->perimeter());

        ui->statusbar->showMessage(result);
    }
}

void MainWindow::centerMassButton_clicked()
{
    if(object){
        QPoint point = object->getCenter();
        QString result;
        result += "x = " + QString::number(point.x()) + "; y = " + QString::number(point.y());
        ui->statusbar->showMessage(result);
    }
}


void MainWindow::changeSizeButton_clicked()
{
    if(object) {
        window.show();
    }
}


