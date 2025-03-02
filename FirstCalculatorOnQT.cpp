#include "FirstCalculatorOnQT.h"
#include <QMainWindow>
#include <QtWidgets/QLineEdit>

FirstCalculatorOnQT::FirstCalculatorOnQT(QWidget *parent) : QMainWindow(parent)
{
    
    ui.setupUi(this);
    lineEdit = ui.lineEdit;
}

FirstCalculatorOnQT::~FirstCalculatorOnQT()
{}
