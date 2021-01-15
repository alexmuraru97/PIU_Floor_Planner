#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include "HandlerButton.h"
#include "Furniture.h"
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>
class FurnitureProperty :public QWidget
{
	Q_OBJECT
private:
	QVBoxLayout layout;
	Furniture* furniture;
	QLabel widthLabel;
	QLabel heightLabel;
	QLineEdit widthTextBox;
	QLineEdit heightTextBox;
public:
	FurnitureProperty(Furniture* furniture, QWidget* parent = nullptr);
public slots:
	void furnitureWidthSetValue();
	void furnitureHeightSetValue();
};

