#include "HandlerButton.h"

HandlerButton::HandlerButton(GlobalStats::SceneOperationType op, void(* fct)(), QWidget* parent):QPushButton(parent)
{
	this->operationType = op;
	this->handlingFunction = fct;

}

void HandlerButton::enterEvent(QEvent* event)
{
	this->setFixedSize(this->width() + 10, this->height() + 10);
}

void HandlerButton::leaveEvent(QEvent* event)
{
	this->setFixedSize(this->width() - 10, this->height() - 10);
}

bool HandlerButton::hitButton(const QPoint& pos) const
{
	GlobalStats::SetOperationType(operationType);
	if(handlingFunction!=nullptr)
	{
		handlingFunction();
	}
	return true;
}

HandlerButton::~HandlerButton()
{
}
