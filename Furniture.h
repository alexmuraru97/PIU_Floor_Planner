#pragma once
#include <QGraphicsPixmapItem>
#include "GlobalStats.h"
#include <QGraphicsSceneMouseEvent>

class Furniture;
#include "FurnitureProperty.h"
class Furniture :public QGraphicsPixmapItem
{
private:
	QImage img;
public:
	
	Furniture(int x, int y,QString path);
	void SetWidth(int width);
	void SetHeight(int height);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
	~Furniture();
};

