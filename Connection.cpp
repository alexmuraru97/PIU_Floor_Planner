#include "Connection.h"

Connection::Connection(int x, int y):QGraphicsEllipseItem()
{
	int gridX = round(x / GlobalStats::GetGridStep()) * GlobalStats::GetGridStep();
	int gridY= round(y / GlobalStats::GetGridStep()) * GlobalStats::GetGridStep();
	this->setRect(QRectF(gridX- GlobalStats::GetConnRadius()/2.0, gridY- GlobalStats::GetConnRadius()/2.0, GlobalStats::GetConnRadius(), GlobalStats::GetConnRadius()));
	point.setX(gridX);
	point.setY(gridY);
}

void Connection::addWall(Wall* wall)
{
	walls.push_back(wall);
}

void Connection::removeWall(Wall* wall)
{
	if(walls.size()>0)
	{
		walls.remove(wall);
	}
	
	//todo check later
	if(walls.size()==0)
	{
		delete this;
	}
}


list<Wall*> Connection::getWalls()
{
	return this->walls;
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
	dragOver = true;
}

void Connection::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	dragOver = false;
	QList<QGraphicsItem*> sc = GlobalStats::GetGraphicsScene()->items();
	QList<QGraphicsItem*>itemList=scene()->collidingItems(this, Qt::IntersectsItemShape);

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
				list<Wall*> thisWalls = this->getWalls();
				list<Wall*> commonWalls;
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
				//if comune
				if(commonWalls.size()==0)
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
						//todo delete duplicate wall;


						this->addWall(wall);
					}
					delete toBeMerged;
					toBeMerged = nullptr;
				}
			}else
			{
				cout << "E invalid gigel" << endl;
			}
		}
	}
}

void Connection::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	GlobalStats::mousePosition.setX(event->pos().x());
	GlobalStats::mousePosition.setY(event->pos().y());
	if(dragOver)
	{
		point.setX(round(event->pos().x()/GlobalStats::GetGridStep())*GlobalStats::GetGridStep());
		point.setY(round(event->pos().y()/GlobalStats::GetGridStep())*GlobalStats::GetGridStep());
		this->setRect(QRectF(point.x() - GlobalStats::GetConnRadius() / 2.0, point.y() - GlobalStats::GetConnRadius() / 2.0, GlobalStats::GetConnRadius(), GlobalStats::GetConnRadius()));
		for (Wall* wall : walls)
		{
			wall->updatePositions();
		}
	}
}



Connection::~Connection()
{

}
