#include "InOutMenuWidget.h"
#include <qlayout.h>
#include "MenuButton.h"
#include <stack>

InOutMenuWidget::InOutMenuWidget()
{
	QStackedWidget* stack = new QStackedWidget;


	this->setMaximumHeight(80);
	this->setMinimumWidth(100);
	this->setStyleSheet("border: 1px solid black");

	QHBoxLayout* hlayout = new QHBoxLayout();
	hlayout->setSpacing(20);
	hlayout->setMargin(20);
	hlayout->setAlignment(Qt::AlignLeft);


	MenuButton* clear = new MenuButton(stack, 1, this);
	clear->setText("Clear");
	clear->setFixedSize(90, 40);
	clear->setStyleSheet("border-width: 2px; border-radius: 20px");

	MenuButton* exp = new MenuButton(stack, 2, this);
	exp->setText("Export");
	exp->setFixedSize(90, 40);
	exp->setStyleSheet("border-width: 2px; border-radius: 20px");

	this->setLayout(hlayout);

	hlayout->insertWidget(1, clear);
	hlayout->insertWidget(2, exp);

	this->show();
}
