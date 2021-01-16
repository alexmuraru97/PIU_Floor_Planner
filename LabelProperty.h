#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include "HandlerButton.h"
#include "Label.h"
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>
class LabelProperty:public QWidget
{
	Q_OBJECT
private:
	QVBoxLayout layout;
	Label* label;

	QLabel labelTextLabel;
	QLineEdit  labelText;


	QLabel fontSizeLabel;
	QLineEdit  fontSize;


	QLabel labelWidthLabel;
	QLineEdit  labelWidth;

	QPushButton labelBolded;
	bool isBolded;
public:
	LabelProperty(Label* label, QWidget* parent = nullptr);
public slots:
	void setLabelText();
	void setFontSize();
	void setLabelWidth();
	void toggleBold();
};

