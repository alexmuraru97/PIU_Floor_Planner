#pragma once

class WallItem;
#include "Connection.h"


class WallItem:public QGraphicsPixmapItem
{
protected:
	Connection* connections[2];
public:
	virtual void updatePositions()=0;
	virtual Connection** getConnections()=0;
	virtual void deatach()=0;
	virtual ~WallItem(){};
};
