#include "Door.h"



Door::Door(Connection* c1, Connection* c2)
{
	img = QImage(GlobalStats::GetDoorIcon());
	connections[0] = c1;
	connections[1] = c2;
	c1->addDoor(this);
	c2->addDoor(this);

	qreal val = sqrt((double)pow(c1->getPoint().x() - c2->getPoint().x(), 2) + (double)pow(c1->getPoint().y() - c2->getPoint().y(), 2)) ;
	this->setPixmap(QPixmap::fromImage(img).scaled(val,val,Qt::KeepAspectRatio));

}

double Door::calculateRotation()
{
	return atan2(connections[0]->getPoint().y() - connections[1]->getPoint().y(), connections[1]->getPoint().x() - connections[0]->getPoint().x()) * 180 / M_PI;
}

void Door::updatePositions()
{
	//TODO IMPLEMENT THIS
	this->setTransformOriginPoint(this->pos().x()-this->pixmap().width(),this->pos().y()+this->pixmap().height());
	cout << calculateRotation() << endl;
	this->setRotation(-calculateRotation());
	this->setX(connections[0]->getPoint().x());
	//cout << "updating doors" << endl;
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
