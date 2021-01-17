#include "Furniture.h"

Furniture::Furniture(int x, int y, QString path):QGraphicsPixmapItem()
{
	img = QImage(path);
	this->setPixmap(QPixmap::fromImage(img));
	this->setScale(0.02);
	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
	this->setX(x);
	this->setY(y);
}

void Furniture::SetWidth(int width)
{
;
	this->setPixmap(QPixmap::fromImage(img).scaled(width, pixmap().height(), Qt::IgnoreAspectRatio));
}

void Furniture::SetHeight(int height)
{
	this->setPixmap(QPixmap::fromImage(img).scaled(pixmap().width(), height, Qt::IgnoreAspectRatio));
}



void Furniture::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		event->ignore();
		return;
	}
	event->accept();
	if (GlobalStats::GetTogglePropertyStatus())
	{
		GlobalStats::ToggleOffPropertyMenu();
	}
	else
	{
		GlobalStats::ToggleOnPropertyMenu(new FurnitureProperty(this));
	}
}

void Furniture::FlipVertically()
{
	this->setPixmap(pixmap().transformed(QTransform().scale(1, -1)));
}

void Furniture::FlipHorizontally()
{
	this->setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
}

Furniture::~Furniture()
{
}
