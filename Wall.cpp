#include "Wall.h"

Wall::Wall(int x1, int y1) :QGraphicsLineItem((qreal)x1, (qreal)y1, 0, 0)
{
	connections[0] = new Connection(x1,y1);
	connections[0]->addWall(this);
	connections[1] = new Connection(0,0);
	connections[1]->addWall(this);
	GlobalStats::GetGraphicsScene()->addItem(connections[0]);
	GlobalStats::GetGraphicsScene()->addItem(connections[1]);
	if(GlobalStats::GetIsShowingConnections())
	{
		showConnections();
	}else
	{
		hideConnections();
	}
	updatePositions();
}

Wall::Wall(int x1, int y1, int x2, int y2) : QGraphicsLineItem((qreal)x1, (qreal)y1, (qreal)x2, (qreal)y2)
{
	connections[0] = new Connection(x1,y1);
	connections[0]->addWall(this);
	connections[1] = new Connection(x2,y2);
	connections[1]->addWall(this);
	GlobalStats::GetGraphicsScene()->addItem(connections[0]);
	GlobalStats::GetGraphicsScene()->addItem(connections[1]);
	if (GlobalStats::GetIsShowingConnections())
	{
		showConnections();
	}
	else
	{
		hideConnections();
	}
	updatePositions();
}

Wall::Wall(Connection* c1, Connection* c2)
{
	connections[0] = c1;
	connections[0]->addWall(this);
	connections[1] = c2;
	connections[1]->addWall(this);
	if (GlobalStats::GetIsShowingConnections())
	{
		showConnections();
	}
	else
	{
		hideConnections();
	}
	updatePositions();
}


//Show Grabbing points on double click
void Wall::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	Wall* aux = nullptr;
	if (GlobalStats::GetIsShowingConnections())
	{
		
		for(QGraphicsItem* item :GlobalStats::GetGraphicsScene()->items())
		{
			aux = dynamic_cast<Wall*>(item);
			if(aux!=nullptr)
			{
				aux->hideConnections();
				aux = nullptr;
			}
		}
	}else
	{
		for (QGraphicsItem* item : GlobalStats::GetGraphicsScene()->items())
		{
			aux = dynamic_cast<Wall*>(item);
			if (aux != nullptr)
			{
				aux->showConnections();
				aux = nullptr;
			}
		}
	}
}


//Wall Split on Right click
void Wall::contextMenuEvent(QGraphicsSceneContextMenuEvent* event)
{
	Connection* midConnection = new Connection(event->pos().x(), event->pos().y());
	Wall* newWall = new Wall(midConnection, connections[1]);
	connections[1]->addWall(newWall);
	connections[1]->removeWall(this);
	GlobalStats::GetGraphicsScene()->addItem(newWall);
	GlobalStats::GetGraphicsScene()->addItem(midConnection);
	connections[1] = midConnection;
	midConnection->addWall(this);
	Wall* aux = nullptr;
	for (QGraphicsItem* item : GlobalStats::GetGraphicsScene()->items())
	{
		aux = dynamic_cast<Wall*>(item);
		if (aux != nullptr)
		{
			aux->showConnections();
			aux = nullptr;
		}
	}
}



//Redraw Lines
void Wall::updatePositions()
{
	this->setLine(connections[0]->getPoint().x(), (qreal)connections[0]->getPoint().y(), (qreal)connections[1]->getPoint().x(), (qreal)connections[1]->getPoint().y());
	setLineWidth();
}

void Wall::hideConnections()
{
	GlobalStats::SetIsShowingConnections(false);
	connections[0]->hide();
	connections[1]->hide();
}

void Wall::showConnections()
{
	GlobalStats::SetIsShowingConnections(true);
	connections[0]->show();
	connections[1]->show();
}

void Wall::setLineWidth()
{
	QPen a(Qt::black, GlobalStats::GetWallWidth());
	this->setPen(a);
}

Connection** Wall::getConnections()
{
	return connections;
}


Wall::~Wall()
{
	if (connections[0]->getWalls().size() <= 1)
	{
		delete connections[0];
		connections[0] = nullptr;
	}
	else
	{
		connections[0]->removeWall(this);

	}
	
	if (connections[1]->getWalls().size() <= 1)
	{
		delete connections[1];
		connections[1] = nullptr;
	}
	else
	{
		connections[1]->removeWall(this);
	}


}
