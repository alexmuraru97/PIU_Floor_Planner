#pragma once
#include <qgraphicsview.h>
#include <qgraphicsitem.h>
#include <QMouseEvent>
#include "Connection.h"

class CustomGraphicsView :public QGraphicsView
{
private:
	QGraphicsItem* current=nullptr;
	QPoint point;
public:
	CustomGraphicsView(QWidget* parent);
	void wheelEvent(QWheelEvent* event) override;
};

