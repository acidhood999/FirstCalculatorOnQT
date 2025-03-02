#pragma once

#include <QtWidgets/QMainWindow>
#include <QString>

#include "ui_FirstCalculatorOnQT.h"


class FirstCalculatorOnQT : public QMainWindow
{
    Q_OBJECT

public:

    QLineEdit* lineEdit = nullptr;
	

    FirstCalculatorOnQT(QWidget *parent = nullptr);
    ~FirstCalculatorOnQT();

private slots:

	void addDigit(QString digit)
	{
		lineEdit->setText(lineEdit->text() + digit);
	}


	void add0() { addDigit("0"); };
	void add1() { addDigit("1"); };
	void add2() { addDigit("2"); };
	void add3() { addDigit("3"); };
	void add4() { addDigit("4"); };
	void add5() { addDigit("5"); };
	void add6() { addDigit("6"); };
	void add7() { addDigit("7"); };
	void add8() { addDigit("8"); };
	void add9() { addDigit("9"); };

	void addFirstOperation(QString op)
	{
		FirstNumber = lineEdit->text().toInt();
		operation = op;
		lineEdit->clear();
	}
	void addSecondNumberAndResult() 
	{ 
		SecondNumber = lineEdit->text().toInt();

		if (operation == "+") { Result = FirstNumber + SecondNumber; }
		else if (operation == "-") { Result = FirstNumber - SecondNumber; }
		else if (operation == "/") { Result = FirstNumber / SecondNumber; }
		else if (operation == "*") { Result = FirstNumber * SecondNumber; }

		lineEdit->setText(QString::number(Result));

		operation.clear();
	}

	void addP() { addFirstOperation("+"); };
	void addM() { addFirstOperation("-"); };
	void addD() { addFirstOperation("/"); };
	void addY() { addFirstOperation("*"); };
	void addR() { addSecondNumberAndResult(); };

	void addClear() { lineEdit->clear(); };

private:

    Ui::FirstCalculatorOnQTClass ui;

	int Result{};
	int FirstNumber{};
	int SecondNumber{};

	QString operation{ "" };


};
