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
		if (lineEdit->text() == "ERROR")
		{
			lineEdit->clear();
			CheckingForError = true;
		}
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

		hasInvalidSign(op);

		operation = op;
		
		lineEdit->clear();
	}

	void addSecondNumberAndResult()
	{

		SecondNumber = lineEdit->text().toInt();


		if (operation == "+" && CheckingForError) { Result = FirstNumber + SecondNumber; }
		else if (operation == "-" && CheckingForError) { Result = FirstNumber - SecondNumber; }
		else if (operation == "/" && CheckingForError)
		{
			if (FirstNumber == 0) { CheckingForError = false; }
			else { Result = FirstNumber / SecondNumber; }

		}
		else if (operation == "*" && CheckingForError) { Result = FirstNumber * SecondNumber; }

		if (CheckingForError) { lineEdit->setText(QString::number(Result)); }
		else
		{
			lineEdit->setText("ERROR");
			CheckingForError = true;
		}

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

	bool CheckingForError { false };

	QString operation{ "" };

	bool hasInvalidSign(QString& op)
	{
		for (QString c : op)
		{
			if (c == "+" || c == "-" || c == "/" || c == "*")
			{
				return CheckingForError = true;
			}
		}
		return CheckingForError = false;
	}

};
