#pragma once
#include <QGraphicsPixmapItem>
#include "GlobalStats.h"
#include <QGraphicsSceneMouseEvent>
class Furniture :public QGraphicsPixmapItem
{
private:
	QImage img;
public:
	
	Furniture(int x, int y,QString path);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
	~Furniture();
};

