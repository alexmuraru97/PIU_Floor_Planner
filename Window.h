#pragma once
#include <QGraphicsPixmapItem>

class Window;
#include "Connection.h"
#include "WallItem.h"

class Window :public WallItem
{
private:
	QImage img;
public:
	Window(Connection* c1, Connection* c2);
	double calculateRotation();

	
	void deatach() override;
	void updatePositions() override;
	Connection** getConnections() override;
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
	
	~Window();
};

