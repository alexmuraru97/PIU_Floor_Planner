#include "MenuButton.h"

MenuButton::MenuButton(QStackedWidget* panel, int index, QWidget* parent) :QPushButton(parent)
{
	this->panel = panel;
	this->index = index;
}

void MenuButton::enterEvent(QEvent* event)
{
	this->setFixedSize(this->width()+10, this->height()+10);
}

void MenuButton::leaveEvent(QEvent* event)
{
	this->setFixedSize(this->width()-10, this->height()-10);
}

bool MenuButton::hitButton(const QPoint& pos) const
{
	panel->setCurrentIndex(index);
	GlobalStats::SetOldPanelIndex(index);
	return true;
}
