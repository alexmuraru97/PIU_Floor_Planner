#include "CustomGraphicsView.h"

CustomGraphicsView::CustomGraphicsView(QWidget* parent):QGraphicsView(parent)
{
	
}

void CustomGraphicsView::wheelEvent(QWheelEvent* event)
{
	if (event->delta() > 0)
	{
		scale(1.10, 1.10);
	}
	else
	{
		scale(0.9, 0.9);
	}
}

