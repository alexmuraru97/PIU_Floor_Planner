#pragma once
#include <qgraphicsitem.h>
#include "GlobalStats.h"


class Label:public QGraphicsTextItem
{
	QColor textColor;
	QFont font;
public:
	Label(QString text,int x, int y);
	void setSize(int size);
	void setBold(bool bold);
	void setColor(QColor color);
	void updateFontData();
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
};

