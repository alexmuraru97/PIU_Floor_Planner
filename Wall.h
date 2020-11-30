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
public:
	Wall(int x1, int y1);
	Wall(int x1, int y1, int x2, int y2);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
	void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;
	void updatePositions();
	void hideConnections();
	void showConnections();
	void setLineWidth();
	Connection** getConnections();
	~Wall();
};
