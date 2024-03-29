#include "Door.h"



Door::Door(Connection* c1, Connection* c2)
{
	img = QImage(GlobalStats::GetDoorIcon()).mirrored();
	this->setPixmap(QPixmap::fromImage(img));
	
	connections[0] = c1;
	connections[1] = c2;
	c1->addWallItem(this);
	c2->addWallItem(this);

	vertMirrored = false;
	updatePositions();
}

double Door::calculateRotation()
{
		return QLineF(connections[0]->getPoint(), connections[1]->getPoint()).angle();
}

void Door::updatePositions()
{
	if(vertMirrored)
	{
		this->setTransformOriginPoint(0, -GlobalStats::GetConnRadius() / 2.0);
		this->setRotation(-abs(calculateRotation()));
		this->setScale(QLineF(connections[0]->getPoint(), connections[1]->getPoint()).length() / (1.0 * this->pixmap().width()));
		double dx = sin(qDegreesToRadians(calculateRotation())) * (double)QLineF(connections[0]->getPoint(), connections[1]->getPoint()).length();
		double dy = cos(qDegreesToRadians(calculateRotation())) * (double)QLineF(connections[0]->getPoint(), connections[1]->getPoint()).length();
		this->setX(connections[0]->getPoint().x()-dx);
		this->setY(connections[0]->getPoint().y()-dy + GlobalStats::GetConnRadius() / 2.0);
	}
	else
	{
		this->setX(connections[0]->getPoint().x());
		this->setY(connections[0]->getPoint().y());
		this->setTransformOriginPoint(0, -GlobalStats::GetConnRadius() / 2.0);
		this->setRotation(-abs(calculateRotation()));
		this->setScale(QLineF(connections[0]->getPoint(), connections[1]->getPoint()).length() / (1.0 * this->pixmap().width()));
	}
	connections[0]->show();
	connections[1]->show();
	this->update();
}

Connection** Door::getConnections()
{
	return connections;
}

void Door::deatach()
{
	try
	{
		connections[0]->removeWallItem(this);
	}
	catch (...)
	{
		cout << "Error deataching door";
	}
	try
	{
		connections[1]->removeWallItem(this);
	}
	catch(...)
	{
		cout << "Error deataching door";
	}

}

void Door::flipDoorVertically()
{
	this->setPixmap(pixmap().transformed(QTransform().scale(1, -1)));
	vertMirrored ? vertMirrored = false : vertMirrored = true;
	updatePositions();
}

void Door::flipDoorHorizontally()
{
	this->setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
	updatePositions();
}


void Door::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		event->ignore();
		return;
	}
	event->accept();
	if(GlobalStats::GetTogglePropertyStatus())
	{
		GlobalStats::ToggleOffPropertyMenu();
	}else
	{
		GlobalStats::ToggleOnPropertyMenu(new DoorProperty(this));
	}
	
}

Door::~Door()
{
	deatach();
}
