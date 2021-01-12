#pragma once
#include <QGraphicsPixmapItem>
#include "GlobalStats.h"
#include <QtMath>

class Door;
#include "Connection.h"



class Door:public QGraphicsPixmapItem
{
private:
	QImage img;
	Connection* connections[2];
public:
	Door(Connection* c1, Connection*c2);
	double calculateRotation();
	void updatePositions();
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
};

