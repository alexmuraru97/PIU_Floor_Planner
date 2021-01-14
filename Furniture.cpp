#include "Furniture.h"

Furniture::Furniture(int x, int y, QString path)
{
	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

void Furniture::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
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