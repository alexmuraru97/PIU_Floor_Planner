#pragma once
#include <list>
#include <QPainter>
#include <iostream>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsEllipseItem>
//solving circular dependency problem
class Connection;
#include "Wall.h"
#include "Door.h"

using namespace std;
class Connection:public QGraphicsEllipseItem
{
private:
	QPoint point;
	list<QGraphicsItem*> connectedItems;
	bool dragOver = false;
public:
	Connection(int x, int y);
	void addWall(Wall* wall);
	void removeWall(Wall* wall);
	void addDoor(Door* door);
	void removeDoor(Door* door);

	int getDoorCount();
	int getWallCount();
	int getItemCount();
	
	list<Wall*> getWalls();
	list<Door*> getDoors();
	list<QGraphicsItem*> getItems();
	
	QPoint getPoint();
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	~Connection();
};
