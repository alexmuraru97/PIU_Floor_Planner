#pragma once
#include <QGraphicsPixmapItem>
#include "GlobalStats.h"
#include <QtMath>

class Door;
#include "Connection.h"



class Door:public QGraphicsPixmapItem
{
private:
	Connection* left;
	Connection* right;
	QImage img;
	Connection* connections[2];
	
public:
	Door(Connection* c1, Connection*c2);
	double calculateRotation();
	void updatePositions();
	void flipDoorVertically();
	void flipDoorHorizontally();
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
};

