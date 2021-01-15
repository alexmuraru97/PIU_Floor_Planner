#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include "HandlerButton.h"
#include "Door.h"
#include <QPushButton>

class DoorProperty:public QWidget
{
	Q_OBJECT
private:
	QVBoxLayout layout;
	Door* door;
	QPushButton* flipVertButton;
	QPushButton* flipHorizontButton;
public:
	DoorProperty(Door* door,QWidget* parent=nullptr);
	~DoorProperty();
public slots:
	void FlipVertically();
	void FlipHorizontally();
};

