#pragma once
#include <QGraphicsPixmapItem>
#include "GlobalStats.h"
#include "Connection.h"

class Door:public QGraphicsPixmapItem
{
private:
	QImage img;
	Connection* connections[2];
public:
	Door(int x, int y, int width, int height);
	Door(Connection* c1, Connection*c2);

	
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
};

