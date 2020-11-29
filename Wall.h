#pragma once
#include <QGraphicsLineItem>
#include "GlobalStats.h"
#include <QPainter>
#include <QGraphicsScene>

//Circular dependency
class Wall;
#include "Connection.h"

class Wall:public QGraphicsLineItem
{
private:
	Connection *connections[2];
	bool showConnection;
public:
	Wall(int x1, int y1);
	Wall(int x1, int y1, int x2, int y2);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
	void updatePositions();
	void hideConnections();
	void showConnections();
	Connection** getConnections();
	~Wall();
};
