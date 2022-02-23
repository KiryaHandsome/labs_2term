#include "rectangle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Truck w;
    w.show();
    w.setWindowTitle("task1");
    w.setGeometry(50, 150, 1400, 600);
    w.setFixedSize(1400, 600);

    //w.setStyleSheet("background-color: white");

    return a.exec();
}
