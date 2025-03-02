#include "FirstCalculatorOnQT.h"
#include <QtWidgets/QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstCalculatorOnQT w;


    w.setWindowTitle("Calculator");
    w.setWindowIcon(QIcon("Icon.png"));

    w.resize(200,450);//200,100
    w.show();
    return a.exec();
}
