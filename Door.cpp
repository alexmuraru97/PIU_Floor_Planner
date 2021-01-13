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
	return atan2(left->getPoint().y() - right->getPoint().y(), right->getPoint().x() - left->getPoint().x()) * 180 / M_PI;
}

void Door::updatePositions()
{
	if(connections[0]->getPoint().x()<connections[1]->getPoint().x())
	{
		left = connections[0];
		right = connections[1];
	}
	else
	{
		left = connections[1];
		right = connections[0];
	}
	this->setTransformOriginPoint(left->getPoint().x(), this->y() + left->getPoint().y());
	this->setRotation(-calculateRotation());
	this->setScale(QLineF(left->getPoint(), right->getPoint()).length() / (1.0 * this->pixmap().width()));
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
