#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "figure.h"
#include "circle.h"
#include "ellipse.h"
#include "rectangle.h"
#include "square.h"
#include "rhomb.h"
#include "parallelogram.h"
#include "fivepointedstar.h"
#include "sixpointedstar.h"
#include "eightpointedstar.h"
#include "hexagon.h"
#include "triangle.h"
#include "dialogwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent* event);
    Figure* object = nullptr;
    QTimer* timer;
    enum Move{
        moveLeft = 0,
        moveRight,
        moveUp,
        moveDown,
        rotateLeft,
        rotateRight,
        zoomIn,
        zoomOut
    };
    DialogWindow window;



private slots:
    void circleButton_clicked();
    void squareButton_clicked();
    void triangleButton_clicked();
    void rectangleButton_clicked();
    void rhombButton_clicked();
    void fivePButton_clicked();
    void sixPButton_clicked();
    void eightPButton_clicked();
    void hexagonButton_clicked();
    void ellipseButton_clicked();
    void parallButton_clicked();

    void zoomInButton_pressed();
    void zoomOutButton_pressed();
    void zoomInButton_released();
    void zoomOutButton_released();

    void rotateLeftButton_pressed();
    void rotateRightButton_pressed();
    void rotateLeftButton_released();
    void rotateRightButton_released();

    void moveLeftButton_pressed();
    void moveRightButton_pressed();
    void moveUpButton_pressed();
    void moveDownButton_pressed();

    void moveLeftButton_released();
    void moveRightButton_released();
    void moveUpButton_released();
    void moveDownButton_released();

    void areaButton_clicked();
    void perimeterButton_clicked();
    void centerMassButton_clicked();
    void changeSizeButton_clicked();
};



#endif // MAINWINDOW_H
