﻿#include "Connection.h"

Connection::Connection(int x, int y):QGraphicsEllipseItem()
{
	int gridX = round(x / GlobalStats::GetGridStep()) * GlobalStats::GetGridStep();
	int gridY= round(y / GlobalStats::GetGridStep()) * GlobalStats::GetGridStep();
	this->setRect(QRectF(gridX- GlobalStats::GetConnRadius()/2.0, gridY- GlobalStats::GetConnRadius()/2.0, GlobalStats::GetConnRadius(), GlobalStats::GetConnRadius()));
	point.setX(gridX);
	point.setY(gridY);
	this->setZValue(std::numeric_limits<qreal>::max());
}

void Connection::addWall(Wall* wall)
{
	connectedItems.push_back(wall);
}

void Connection::removeWall(Wall* wall)
{
	if(getWallCount()>0)
	{
		connectedItems.remove(wall);
	}
	if(getItemCount()==1&&dynamic_cast<WallItem*>(connectedItems.front())!=nullptr)
	{
		WallItem* tempDoor = dynamic_cast<WallItem*>(connectedItems.front());
		tempDoor->deatach();
		delete tempDoor;
	}
	if(connectedItems.size()==0)
	{
		delete this;
	}
}

void Connection::addWallItem(WallItem* door)
{
	connectedItems.push_back(door);
}

void Connection::removeWallItem(WallItem* door)
{
	if (getWallItemCount() > 0)
	{
		connectedItems.remove(door);
	}
}


int Connection::getWallItemCount()
{
	return getWallItem().size();
}

int Connection::getWallCount()
{
	return getWalls().size();
}

int Connection::getItemCount()
{
	return connectedItems.size();
}


list<Wall*> Connection::getWalls()
{
	list<Wall*> temp;
	for(QGraphicsItem* item: connectedItems)
	{
		if(dynamic_cast<Wall*>(item)!=nullptr)
		{
			temp.push_back(dynamic_cast<Wall*>(item));
		}
	}
	return temp;
}

list<WallItem*> Connection::getWallItem()
{
	list<WallItem*> temp;
	for (QGraphicsItem* item : connectedItems)
	{
		if (dynamic_cast<WallItem*>(item) != nullptr)
		{
			temp.push_back(dynamic_cast<WallItem*>(item));
		}
	}
	return temp;
}

list<QGraphicsItem*> Connection::getItems()
{
	return this->connectedItems;
}


QPoint Connection::getPoint()
{
	QPoint a;
	a.setX(point.x());
	a.setY(point.y());
	return a;
}

void Connection::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if(event->button()!=Qt::LeftButton)
	{
		event->ignore();
		return;
	}
	event->accept();
}

void Connection::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		event->ignore();
		return;
	}
	event->accept();
	QList<QGraphicsItem*>itemList=scene()->collidingItems(this, Qt::IntersectsItemShape);

	//Daca fac merge pe alt Connection
	Connection* toBeMerged=nullptr;
	for(QGraphicsItem*item: itemList)
	{
		if(dynamic_cast<Connection*>(item)!=nullptr)
		{
			toBeMerged = dynamic_cast<Connection*>(item);
			break;
		}
	}
	if(toBeMerged!=nullptr)
	{
		//verific daca nodul e valid (daca nu face parte din acelasi perete)
		//tobeMerged, cel pe care ajung
		//this, obiectul pe care il mut
		list<Wall*> neighbourWalls=this->getWalls();
		bool isValidWall = true;
		if(neighbourWalls.size()>0)
		{
			for(Wall* neighbourWall:neighbourWalls)
			{
				Connection** neighbourConnections = neighbourWall->getConnections();
				if(neighbourConnections !=nullptr)
				{
					if(neighbourConnections[0]==toBeMerged|| neighbourConnections[1]==toBeMerged)
					{
						isValidWall = false;
						break;
					}
				}
			}
			if(isValidWall)
			{
				list<Wall*> tbrWalls = toBeMerged->getWalls();
				list<WallItem*> tbrWallItems = toBeMerged->getWallItem();
				
				list<Wall*> thisWalls = this->getWalls();
				list<WallItem*> thisWallsItems = this->getWallItem();
				
				list<Wall*> commonWalls;
				list<WallItem*> commonWallItems;

				//For items(door/windows)
				for (WallItem* thisWallitem : thisWallsItems)
				{
					for (WallItem* tbrWallItem : tbrWallItems)
					{
						if (tbrWallItem->getConnections()[0] == thisWallitem->getConnections()[0] || tbrWallItem->getConnections()[0] == thisWallitem->getConnections()[1] || tbrWallItem->getConnections()[1] == thisWallitem->getConnections()[0] || tbrWallItem->getConnections()[1] == thisWallitem->getConnections()[1])
						{
							commonWallItems.push_back(tbrWallItem);
						}
					}
				}

				//For walls
				for(Wall* thisWall:thisWalls)
				{
					for(Wall* tbrWall:tbrWalls)
					{
						if(tbrWall->getConnections()[0]==thisWall->getConnections()[0]|| tbrWall->getConnections()[0] == thisWall->getConnections()[1]|| tbrWall->getConnections()[1] == thisWall->getConnections()[0]|| tbrWall->getConnections()[1] == thisWall->getConnections()[1])
						{
							commonWalls.push_back(tbrWall);
						}
					}
				}

				if(commonWalls.size()==0||commonWallItems.size()!=0)
				{
					for (Wall* wall : tbrWalls)
					{
						//verifica daca conn[0] sau conn[1]sunt comune
						Connection** conn = wall->getConnections();
						if (conn[0] == toBeMerged)
						{
							conn[0] = this;
						}
						if (conn[1] == toBeMerged)
						{
							conn[1] = this;
						}
						this->addWall(wall);
					}

					for (WallItem* wallItem : tbrWallItems)
					{
						//verifica daca conn[0] sau conn[1]sunt comune
						Connection** conn = wallItem->getConnections();
						if (conn[0] == toBeMerged)
						{
							conn[0] = this;
						}
						if (conn[1] == toBeMerged)
						{
							conn[1] = this;
						}
						this->addWallItem(wallItem);
					}
					delete toBeMerged;
					toBeMerged = nullptr;
				}
			}
		}
		for(Wall* wall:getWalls())
		{
			wall->updatePositions();
		}
		for (QGraphicsItem* items : getItems())
		{
			if(dynamic_cast<WallItem*>(items) !=nullptr)
			{
				dynamic_cast<WallItem*>(items)->updatePositions();
			}
			
		}
		return;
	}
	
	for (QGraphicsItem* item : itemList)
	{
		if (dynamic_cast<Wall*>(item) != nullptr && !(dynamic_cast<Wall*>(item)->containsConnection(this)))
		{
			Wall* wall = dynamic_cast<Wall*>(item);
			Wall* newWall = new Wall(this, wall->getConnections()[1]);
			wall->getConnections()[1] = this;
			this->addWall(wall);
			GlobalStats::GetGraphicsScene()->addItem(newWall);
			wall->updatePositions();
			newWall->updatePositions();
			
			break;
		}
	}
}

void Connection::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	GlobalStats::mousePosition.setX(event->pos().x());
	GlobalStats::mousePosition.setY(event->pos().y());

	point.setX(round(event->pos().x()/GlobalStats::GetGridStep())*GlobalStats::GetGridStep());
	point.setY(round(event->pos().y()/GlobalStats::GetGridStep())*GlobalStats::GetGridStep());
	this->setRect(QRectF(point.x() - GlobalStats::GetConnRadius() / 2.0, point.y() - GlobalStats::GetConnRadius() / 2.0, GlobalStats::GetConnRadius(), GlobalStats::GetConnRadius()));
	for (Wall* wall : getWalls())
	{
		wall->updatePositions();
	}
	for (WallItem* wallItems : getWallItem())
	{
		wallItems->updatePositions();
	}

}



Connection::~Connection()
{

}
