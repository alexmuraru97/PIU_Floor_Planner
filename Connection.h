#pragma once
#include <list>
#include <QPainter>
#include <iostream>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsEllipseItem>
//solving circular dependency problem
class Connection;
#include "Wall.h"

using namespace std;
class Connection:public QGraphicsEllipseItem
{
private:
	QPoint point;
	list<Wall*> walls;
	bool dragOver = false;
public:
	Connection(int x, int y);
	void addWall(Wall* wall);
	void removeWall(Wall* wall);
	list<Wall*> getWalls();
	QPoint getPoint();
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

	~Connection();
};
