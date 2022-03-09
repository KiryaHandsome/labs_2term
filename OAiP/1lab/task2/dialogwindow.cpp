#include "dialogwindow.h"
#include "ui_dialogwindow.h"
//#include <QString>
#include <QMessageBox>
#include "circle.h"
#include "ellipse.h"
#include "rectangle.h"
#include "square.h"
#include "rhomb.h"
#include "parallelogram.h"
#include "fivepointedstar.h"    //include all classes for dynamic_cast
#include "sixpointedstar.h"
#include "eightpointedstar.h"
#include "hexagon.h"
#include "triangle.h"

DialogWindow::DialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWindow)
{
    ui->setupUi(this);

    connect(ui->enterButton, SIGNAL(clicked()), this, SLOT(enterButton_clicked()));
}

DialogWindow::~DialogWindow()
{
    delete ui;
}
void DialogWindow::setNewSize(int num1, int num2, int num3)
{
    QString name = typeid(*currentFigure).name();
    if(name == "6Circle"){
        Circle* circle = dynamic_cast<Circle*>(currentFigure);
        if(circle) circle->setSize(num1);
    }
    else if(name == "6Square"){
        Square* square = dynamic_cast<Square*>(currentFigure);
        if(square) square->setSize(num1);
    }
    else if(name == "9Rectangle"){
        Rectangle* rectangle = dynamic_cast<Rectangle*>(currentFigure);
        if(rectangle) rectangle->setSize(num1, num2);
    }
    else if(name == "7Ellipse"){
        Ellipse* ellipse = dynamic_cast<Ellipse*>(currentFigure);
        if(ellipse) ellipse->setSize(num1, num2);
   }
    else if(name == "7Hexagon"){
        Hexagon* hexagon = dynamic_cast<class Hexagon*>(currentFigure);
        if(hexagon) hexagon->setSize(num1);
    }
    else if(name == "5Rhomb"){
        Rhomb* rhomb = dynamic_cast<class Rhomb*>(currentFigure);
        if(rhomb) rhomb->setSize(num1, num2);
    }
    else if(name == "15FivePointedStar" || name == "14SixPointedStar" || name == "16EightPointedStar"){
        Star* star = dynamic_cast<Star*>(currentFigure);
        if(star) star->setSize(num1, num2);
    }
    else if(name == "8Triangle"){
        Triangle* triangle = dynamic_cast<Triangle*>(currentFigure);
        if(triangle) triangle->setSize(num1);
    }
    else {
        Parallelogram* parallelogram = dynamic_cast<Parallelogram*>(currentFigure);
        if(parallelogram) parallelogram->setSize(num1, num2, num3);
    }
}

void DialogWindow::enterButton_clicked()
{
    QString number1(ui->lineEdit1->text());
    QString number2(ui->lineEdit2->text());     //read text from lineEdits
    QString number3(ui->lineEdit3->text());

    int num1 = 100, num2 = 100, num3 = 100;   //equals 100 for case when lineEdit->text() == ""

    if(ui->lineEdit1->isVisible()) num1 = number1.toInt();
    if(ui->lineEdit2->isVisible()) num2 = number2.toInt();    //convert to numbers
    if(ui->lineEdit3->isVisible()) num3 = number3.toInt();

    qDebug() << number1 << " " << number2 << " " << number3 << "\n";
    if(num1 <= 0 || num2 <= 0 ||  num3 <= 0
              || num1 > 400 || num2 > 400 || num3 > 180){
        QMessageBox::warning(this, "Error","Invalid input!!!\nTry again.");
    } else {
        this->hide();
        this->setNewSize(num1, num2, num3);
    }
}

void DialogWindow::setLabelText(Figure* object)
{
    currentFigure = object;   //initialize pointer for using in this class

    ui->lineEdit1->setText("");
    ui->lineEdit2->setText("");     //clear lineEdits
    ui->lineEdit3->setText("");

    ui->lineEdit1->setVisible(true);
    ui->lineEdit2->setVisible(true);
    ui->lineEdit3->setVisible(true);

    QString name = typeid(*currentFigure).name();
    if(name == "6Circle"){
        ui->label->setText("Enter radius of circle (0 < r < 400)");
        ui->lineEdit2->setVisible(false);
        ui->lineEdit3->setVisible(false);
    }
    else if(name == "6Square"){
        ui->label->setText("Enter side of square (0 < a < 400)");
        ui->lineEdit2->setVisible(false);
        ui->lineEdit3->setVisible(false);
    }
    else if(name == "9Rectangle"){
        ui->label->setText("Enter width and heigt of rectangle (0 < width, height < 400)");
        ui->lineEdit3->setVisible(false);
    }
    else if(name == "7Ellipse"){
        ui->label->setText("Enter width and heigt of ellipse (0 < width, height < 400)");
        ui->lineEdit3->setVisible(false);
   }
    else if(name == "7Hexagon"){
        ui->label->setText("Enter radius of circle around hexagon (0 < r < 400)");
        ui->lineEdit2->setVisible(false);
        ui->lineEdit3->setVisible(false);
    }
    else if(name == "5Rhomb"){
        ui->label->setText("Enter width and heigt of rhomb (0 < width, height < 400)");
        ui->lineEdit3->setVisible(false);
    }
    else if(name == "15FivePointedStar" || name == "14SixPointedStar" || name == "16EightPointedStar"){
        ui->label->setText("Enter inner and outer radius around star (0 < r < 400)");
        ui->lineEdit3->setVisible(false);
    }
    else if(name == "8Triangle"){
        ui->label->setText("Enter radius of circle around triangle(0 < r < 400)");
        ui->lineEdit2->setVisible(false);
        ui->lineEdit3->setVisible(false);
    }
    else {
        ui->label->setText("Enter sides and angle between them of (0 < a, b < 400; 0 < angle < 180)");
    }
}
