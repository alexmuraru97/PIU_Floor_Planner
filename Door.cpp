#include "Door.h"



Door::Door(Connection* c1, Connection* c2)
{
	img = QImage(GlobalStats::GetDoorIcon());
	connections[0] = c1;
	connections[1] = c2;
	c1->addDoor(this);
	c2->addDoor(this);


	

	
}

double Door::calculateRotation()
{
	return 0;
	//return atan((connections[0]->getPoint().y() - connections[1]->getPoint().y())*1.0 / (1.0*(connections[1]->getPoint().x() - connections[0]->getPoint().x())));
}

void Door::updatePositions()
{
	//TODO IMPLEMENT THIS
	cout << calculateRotation() << endl;
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
