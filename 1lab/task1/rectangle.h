#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class Rectangle; }
QT_END_NAMESPACE

class Rectangle : public QMainWindow
{
    Q_OBJECT

public:
    Rectangle(QWidget *parent = nullptr);
    ~Rectangle();
    QPixmap* image;

    virtual void keyPressEvent(QKeyEvent*);

protected:
    int x, y;
    Ui::Rectangle *ui;
    QLabel* label;
};

class Truck : public Rectangle
{
private:
    QLabel* chassis;
    QLabel* wheel1;
    QLabel* wheel2;
    QPixmap* wheelImage;
    int angle = 0;
    int wheelAngle = 0;
public:
    Truck();
    void keyPressEvent(QKeyEvent*);
    ~Truck();
};

#endif // RECTANGLE_H
