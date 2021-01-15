#pragma once
#include <QGraphicsPixmapItem>
#include "GlobalStats.h"
#include <QtMath>



class Door;
#include "Connection.h"
#include "WallItem.h"
#include "DoorProperty.h"
class Door:public WallItem
{
private:
	QImage img;
	bool vertMirrored;
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

