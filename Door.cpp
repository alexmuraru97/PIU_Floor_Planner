#include "Door.h"



Door::Door(Connection* c1, Connection* c2)
{
	img = QImage(GlobalStats::GetDoorIcon());
	connections[0] = c1;
	connections[1] = c2;
	c1->addDoor(this);
	c2->addDoor(this);
	this->setPixmap(QPixmap::fromImage(img.scaled(abs(c1->getPoint().x()-c2->getPoint().x()), abs(c1->getPoint().y() - c2->getPoint().y()), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
	this->setPos((c1->getPoint().x() + c2->getPoint().x())/2, (c1->getPoint().y() - c2->getPoint().y())/2);
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
