#pragma once
#include <QLabel>
#include <iostream>
#include "GlobalStats.h"
class FurnitureIcon:public QLabel
{
private:
	QString textData;
	QImage* furnitureIconImg;
public:
	FurnitureIcon(QString path, QImage* img,QWidget* parent=nullptr);
	void mousePressEvent(QMouseEvent* event) override;
	~FurnitureIcon(){};
};

