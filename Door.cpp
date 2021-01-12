#include "Door.h"


Door::Door(int x, int y, int width, int height)
{
	this->setPos(x, y);
	img = QImage(GlobalStats::GetDoorIcon());
	this->setPixmap(QPixmap::fromImage(img.scaled(width,height,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
}

Door::Door(Connection* c1, Connection* c2)
{
	connections[0] = c1;
	connections[1] = c2;
}


void Door::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	if(GlobalStats::GetTogglePropertyStatus())
	{
		GlobalStats::ToggleOffPropertyMenu();
	}else
	{
		GlobalStats::ToggleOnPropertyMenu();
	}
	
}
