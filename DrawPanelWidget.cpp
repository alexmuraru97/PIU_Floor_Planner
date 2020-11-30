#include "DrawPanelWidget.h"
#include <iostream>
#include "Wall.h"
#include "GlobalStats.h"
#include "CustomGraphicsView.h"

DrawPanelWidget::DrawPanelWidget()
{
	this->setStyleSheet("border: 1px solid black");

	//Init scene
	scene = new QGraphicsScene();
	GlobalStats::SetGraphicsScene(scene);
	view = new CustomGraphicsView(this);
	view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	view->setFixedWidth(this->size().width());
	view->setFixedHeight(this->size().height());
	//view->setInteractive(true);
	view->setDragMode(QGraphicsView::ScrollHandDrag);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	
	//create wall
	scene->addItem(new Wall(10, 10, 100, 100));
	scene->addItem(new Wall(10, 30, 100, 120));
	scene->addItem(new Wall(10, 50, 100, 140));
	scene->addItem(new Wall(10, 70, 100, 160));
	scene->addItem(new Wall(10, 90, 100, 180));
	scene->addItem(new Wall(10, 110, 100, 200));
	scene->addItem(new Wall(10, 130, 100, 220));
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
	if(event->key()==Qt::Key_W)
	{
		scene->addItem(new Wall(GlobalStats::mousePosition.x()-25, GlobalStats::mousePosition.y(), GlobalStats::mousePosition.x()+25, GlobalStats::mousePosition.y()));
	}

}


