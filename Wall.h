#pragma once
#include <QGraphicsLineItem>
#include "GlobalStats.h"
#include <QPainter>
#include <QGraphicsScene>
#include <math.h>
#include <QGraphicsSceneContextMenuEvent>

//Circular dependency
class Wall;
#include "Connection.h"
#include "Window.h"
#include "WallProperty.h"

class Wall:public QGraphicsLineItem
{
private:
	Connection *connections[2];
public:
	Wall(int x1, int y1);
	Wall(int x1, int y1, int x2, int y2);
	Wall(Connection* c1, Connection* c2);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
	void updatePositions();
	void hideConnections();
	void showConnections();
	void setLineWidth();
	void splitWall(QPointF pos);
	bool containsConnection(Connection* conn);
	Connection** getConnections();
	void addDoor();
	void addWindow();
	~Wall();
};
