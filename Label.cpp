#include "Label.h"



Label::Label(QString text, int x, int y)
{
	setFlags(QGraphicsItem::ItemIsMovable  |	QGraphicsItem::ItemIsSelectable);
	this->setPos(x, y);
	
	
	this->setSize(20);
	this->setBold(true);
	this->setColor(QColor(0, 0, 0));
	this->setPlainText(text);
}

void Label::setSize(int size)
{
	font.setPixelSize(size);
	updateFontData();
}

void Label::setBold(bool bold)
{
	font.setBold(bold);
	updateFontData();
}

void Label::setColor(QColor color)
{
	textColor = color;
	this->setDefaultTextColor(textColor);
}

void Label::updateFontData()
{
	this->setFont(font);
}


void Label::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	if (GlobalStats::GetTogglePropertyStatus())
	{
		GlobalStats::ToggleOffPropertyMenu();
	}
	else
	{
		GlobalStats::ToggleOnPropertyMenu();
	}
}
