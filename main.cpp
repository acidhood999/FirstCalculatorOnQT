#include "FirstCalculatorOnQT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstCalculatorOnQT w;
    w.resize(200,450);//200,100
    w.show();
    return a.exec();
}
