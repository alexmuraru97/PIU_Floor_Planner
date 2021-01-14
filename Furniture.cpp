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
		GlobalStats::ToggleOnPropertyMenu();
	}
}

Furniture::~Furniture()
{
}
