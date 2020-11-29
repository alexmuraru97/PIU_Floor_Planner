#include "MenuWidget.h"
#include "MenuButton.h"
#include <qlayout.h>

MenuWidget::MenuWidget(QStackedWidget* stack): QWidget()
{
	this->setMinimumSize(400, 80);
	this->setMaximumHeight(80);
	this->setStyleSheet("border: 1px solid black");
	QHBoxLayout* hlayout = new QHBoxLayout();
	hlayout->setSpacing(0);

	MenuButton* floor = new MenuButton(stack,0,this);
	floor->setStyleSheet("border-image:url(./Assets/MenuIcons/floor.png);");
	floor->setFixedSize(50, 50);

	MenuButton* draw = new MenuButton(stack,1,this);
	draw->setStyleSheet("border-image:url(./Assets/MenuIcons/draw.png);");
	draw->setFixedSize(50, 50);

	MenuButton* label = new MenuButton(stack,2,this);
	label->setStyleSheet("border-image:url(./Assets/MenuIcons/label.png);");
	label->setFixedSize(60, 60);

	MenuButton* furniture = new MenuButton(stack,3,this);
	furniture->setStyleSheet("border-image:url(./Assets/MenuIcons/furniture.png);");
	furniture->setFixedSize(60, 60);

	this->setLayout(hlayout);
	hlayout->insertWidget(0, floor);
	hlayout->insertWidget(1, draw);
	hlayout->insertWidget(2, label);
	hlayout->insertWidget(3, furniture);
}
