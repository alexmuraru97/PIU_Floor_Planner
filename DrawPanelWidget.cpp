#include "DrawPanelWidget.h"


#include "CustomScene.h"
#include "Label.h"


DrawPanelWidget::DrawPanelWidget()
{
	this->setStyleSheet("border: 1px solid black");
	setMouseTracking(true);
	
	//Init scene
	scene = new CustomScene();
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

//Map keys on operations
void DrawPanelWidget::keyPressEvent(QKeyEvent* event)
{
	if(event->key()==Qt::Key_W)
	{
		GlobalStats::currentOperation = GlobalStats::SceneOperationType::INSERT_WALL;
		cout << "Current Operation: Wall insert" << endl;
	}
	else if(event->key()==Qt::Key_Delete)
	{
		GlobalStats::currentOperation = GlobalStats::SceneOperationType::DELETE;
		cout << "Current Operation: Delete" << endl;
	}
	else if (event->key() == Qt::Key_D)
	{
		GlobalStats::currentOperation = GlobalStats::SceneOperationType::INSERT_DOOR;
		cout << "Current Operation: Insert Door" << endl;
	}
	else if (event->key() == Qt::Key_F)
	{
		GlobalStats::currentOperation = GlobalStats::SceneOperationType::INSERT_WINDOW;
		cout << "Current Operation: Insert Window" << endl;
	}
	else if (event->key() == Qt::Key_L)
	{
		GlobalStats::currentOperation = GlobalStats::SceneOperationType::INSERT_LABEL;
		cout << "Current Operation: Insert Label" << endl;
	}
}

//Map operations on Middle Scroll button
void DrawPanelWidget::mousePressEvent(QMouseEvent* event)
{
	if(event->button()!=Qt::MidButton)
	{
		event->ignore();
		return;
	}
	
	QPointF mousePoint = view->mapToScene(event->pos());
	switch(GlobalStats::currentOperation)
	{
		case GlobalStats::SceneOperationType::NONE:
			cout << "No operation selected" << endl;
			break;

		case GlobalStats::SceneOperationType::INSERT_WALL:
			{
				GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;
				scene->addItem(new Wall(mousePoint.x() - 25, mousePoint.y(), mousePoint.x() + 25, mousePoint.y()));
			}
			break;
		
		case GlobalStats::SceneOperationType::DELETE:
			{
				GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;
				for (QGraphicsItem* item : scene->items())
				{
					if (dynamic_cast<Wall*>(item) != nullptr)
					{
						dynamic_cast<Wall*>(item)->hideConnections();
					}
				}
				QGraphicsItem* it = scene->itemAt(mousePoint, QTransform());
				if (dynamic_cast<Wall*>(it) != nullptr || dynamic_cast<Door*>(it) != nullptr || dynamic_cast<Window*>(it) != nullptr || dynamic_cast<Label*>(it) != nullptr)
				{
					scene->removeItem(it);
					delete it;
				}
			}
			break;

		case GlobalStats::SceneOperationType::INSERT_DOOR:
			{
				GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;
				QGraphicsItem* it = scene->itemAt(mousePoint, QTransform());
				if (dynamic_cast<Wall*>(it) != nullptr)
				{
					dynamic_cast<Wall*>(it)->addDoor();
				}
			}
			break;

		case GlobalStats::SceneOperationType::INSERT_WINDOW:
			{
				GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;
				QGraphicsItem* it = scene->itemAt(mousePoint, QTransform());
				if (dynamic_cast<Wall*>(it) != nullptr)
				{
					dynamic_cast<Wall*>(it)->addWindow();
				}
			}
			break;

		case GlobalStats::SceneOperationType::INSERT_LABEL:
			{
				GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;
				scene->addItem(new Label("Test message long", mousePoint.x(), mousePoint.y()));
			}
			break;
	}
}



