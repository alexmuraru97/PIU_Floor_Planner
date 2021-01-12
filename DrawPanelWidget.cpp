#include "DrawPanelWidget.h"


DrawPanelWidget::DrawPanelWidget()
{
	this->setStyleSheet("border: 1px solid black");
	setMouseTracking(true);
	
	//Init scene
	scene = new QGraphicsScene();
	GlobalStats::SetGraphicsScene(scene);
	view = new CustomGraphicsView(this);
	view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	view->setFixedWidth(this->size().width());
	view->setFixedHeight(this->size().height());
	view->setDragMode(QGraphicsView::ScrollHandDrag);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	
	//create wall
	scene->addItem(new Wall(10, 10, 100, 100));
	scene->addItem(new Wall(10, 30, 100, 120));
	scene->addItem(new Wall(10, 50, 100, 140));
	//Show whole scene
	view->setScene(scene);
	view->show();

}

void DrawPanelWidget::resizeEvent(QResizeEvent* event)
{
	view->setFixedWidth(this->size().width());
	view->setFixedHeight(this->size().height());
}

void DrawPanelWidget::keyPressEvent(QKeyEvent* event)
{
	QPointF mousePoint = view->mapToScene(view->mapFromGlobal(QCursor::pos()));
	if(event->key()==Qt::Key_W)
	{
		scene->addItem(new Wall(mousePoint.x()-25, mousePoint.y(), mousePoint.x()+25, mousePoint.y()));
	}
	else if(event->key()==Qt::Key_Delete)
	{
		for(QGraphicsItem* item:scene->items())
		{
			if (dynamic_cast<Wall*>(item) != nullptr)
			{
				dynamic_cast<Wall*>(item)->hideConnections();
			}
		}
		QGraphicsItem* it = scene->itemAt(mousePoint, QTransform());
		if(dynamic_cast<Wall*>(it)!=nullptr)
		{
			Wall* temp = dynamic_cast<Wall*>(it);
			scene->removeItem(temp);
			delete temp;
			temp = nullptr;
		}
	}
	else if (event->key() == Qt::Key_D)
	{
		scene->addItem(new Door(mousePoint.x(), mousePoint.y(), 150, 150));
	}
	
}


