#include "DoorProperty.h"

DoorProperty::DoorProperty(Door* door,QWidget* parent):QWidget(parent)
{
	this->door = door;
	this->setLayout(&layout);
	layout.setAlignment(Qt::AlignTop);
	layout.setSpacing(40);
	
	flipVertButton=new QPushButton("Flip Vertically");
	flipVertButton->setFixedHeight(60);
	flipVertButton->setStyleSheet("border-width: 2px; border-radius: 20px");
	QFont font = flipVertButton->font();
	font.setPointSize(14);
	flipVertButton->setFont(font);
	
	
	
	flipHorizontButton=new QPushButton("Flip Horizontally");

	flipHorizontButton->setStyleSheet("border-width: 2px; border-radius: 20px");
	flipHorizontButton->setFixedHeight(60);
	QFont font1 = flipHorizontButton->font();
	font.setPointSize(14);
	flipHorizontButton->setFont(font);
	
	layout.addWidget(flipVertButton);
	layout.addWidget(flipHorizontButton);

	connect(flipVertButton, &QPushButton::pressed, this, &DoorProperty::FlipVertically);
	connect(flipHorizontButton, &QPushButton::pressed, this, &DoorProperty::FlipHorizontally);
}

void DoorProperty::FlipVertically()
{
	this->door->flipDoorVertically();
}

void DoorProperty::FlipHorizontally()
{
	this->door->flipDoorHorizontally();
}
