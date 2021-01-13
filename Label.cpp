#include "Label.h"

#include <qtextoption.h>
#include <qtextdocument.h>

Label::Label(QString text, int x, int y, int textSize, int textWidth)
{
	setFlags(QGraphicsItem::ItemIsMovable |QGraphicsItem::ItemIsSelectable);
	this->setPos(x, y);
	
	setSize(textSize);
	setBold(true);
	setColor(QColor(0, 0, 0));
	setAlignment(Qt::AlignCenter);
	
	//implicit functions
	this->setPlainText(text);
	this->setTextWidth(textWidth);

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

void Label::setAlignment(Qt::Alignment align)
{
	QTextOption option = this->document()->defaultTextOption();
	option.setAlignment(align);
	this->document()->setDefaultTextOption(option);
}


void Label::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	if (event->button() == Qt::MidButton)
	{
		event->ignore();
		return;
	}
	if (GlobalStats::GetTogglePropertyStatus())
	{
		GlobalStats::ToggleOffPropertyMenu();
	}
	else
	{
		GlobalStats::ToggleOnPropertyMenu();
	}
}
