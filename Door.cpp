#include "Door.h"



Door::Door(Connection* c1, Connection* c2)
{
	img = QImage(GlobalStats::GetDoorIcon()).mirrored();
	this->setPixmap(QPixmap::fromImage(img));
	connections[0] = c1;
	connections[1] = c2;
	c1->addDoor(this);
	c2->addDoor(this);

	updatePositions();
}

double Door::calculateRotation()
{
	return atan2(connections[0]->getPoint().y() - connections[1]->getPoint().y(), connections[1]->getPoint().x() - connections[0]->getPoint().x()) * 180 / M_PI;
}

void Door::updatePositions()
{
	this->setTransformOriginPoint(connections[0]->getPoint().x(), this->y()+connections[0]->getPoint().y());
	this->setRotation(-calculateRotation());
	this->setScale(QLineF(connections[1]->getPoint(),connections[0]->getPoint()).length()/(1.0*this->pixmap().width()));
	this->update();
}

void Door::flipDoorVertically()
{
	this->setPixmap(pixmap().transformed(QTransform().scale(1, -1)));
}

void Door::flipDoorHorizontally()
{
	this->setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
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
