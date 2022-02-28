#include "canvas.h"
#include "ui_canvas.h"
#include <QMouseEvent>
#include <QVector>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    this->setWindowTitle("Press double-click to clear window");
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    for(int i = 0; i < points.size() - 1; i++){
        painter.drawLine(points[i], points[i + 1]);
    }
    if(points.size() != 0) painter.drawLine(points[points.size() - 1], currPos);
}
void Canvas::mousePressEvent(QMouseEvent* event)
{
    points.push_back(event->pos());
    currPos = event->pos();
    repaint();

}
void Canvas::mouseMoveEvent(QMouseEvent* event)
{
    currPos = event->pos();
    repaint();
}
void Canvas::mouseReleaseEvent(QMouseEvent* event)
{
    points.push_back(event->pos());
    repaint();
}
void Canvas::mouseDoubleClickEvent(QMouseEvent *event)
{
    points.clear();
    repaint();
}
