#pragma once
#include <QGraphicsPixmapItem>
#include "GlobalStats.h"
#include <QtMath>



class Door;
#include "Connection.h"
#include "WallItem.h"

class Door:public WallItem
{
private:
	Connection* left;
	Connection* right;
	QImage img;

public:
	Door(Connection* c1, Connection*c2);
	double calculateRotation();
	void updatePositions() override;
	Connection** getConnections() override;
	void deatach() override;
	void flipDoorVertically();
	void flipDoorHorizontally();
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
	~Door();
};

