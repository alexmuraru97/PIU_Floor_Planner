#include "DrawPanelWidget.h"


#include "CustomScene.h"
#include "Label.h"


DrawPanelWidget::DrawPanelWidget()
{
	roomStageCycle = true;
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
	else if (event->key() == Qt::Key_R)
	{
		GlobalStats::currentOperation = GlobalStats::SceneOperationType::INSERT_ROOM;
		cout << "Current Operation: Insert Room" << endl;
	}
	else if (event->key() == Qt::Key_S)
	{
		if(event->modifiers()&Qt::ControlModifier)
		{
			cout << "Current Operation: Export Data" << endl;
			GlobalStats::ExportProject();
		}
	}
	else if (event->key() == Qt::Key_C)
	{
		cout << "Current Operation: Clear Scene" << endl;
		GlobalStats::ClearScene();
	}
}

//Map operations on Middle Scroll button
void DrawPanelWidget::mousePressEvent(QMouseEvent* event)
{
	
	QPointF mousePoint = view->mapToScene(event->pos());
	switch(GlobalStats::currentOperation)
	{
		case GlobalStats::SceneOperationType::NONE:
			{
				cout << "No operation selected" << endl;
			}
			break;

		case GlobalStats::SceneOperationType::INSERT_WALL:
			{
				GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;
				scene->addItem(new Wall(mousePoint.x() - 25, mousePoint.y(), mousePoint.x() + 25, mousePoint.y()));
			}
			break;
		
		case GlobalStats::SceneOperationType::DELETE:
			{
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
					GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;
				}
			}
			break;

		case GlobalStats::SceneOperationType::INSERT_DOOR:
			{
				QGraphicsItem* it = scene->itemAt(mousePoint, QTransform());
				if (dynamic_cast<Wall*>(it) != nullptr)
				{
					GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;
					dynamic_cast<Wall*>(it)->addDoor();
				}
			}
			break;

		case GlobalStats::SceneOperationType::INSERT_WINDOW:
			{
				QGraphicsItem* it = scene->itemAt(mousePoint, QTransform());
				if (dynamic_cast<Wall*>(it) != nullptr)
				{
					GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;
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

		case GlobalStats::SceneOperationType::INSERT_ROOM:
		{
			static QPointF firstPoint;
			static Connection* firstPointConnection;
			if(roomStageCycle)
			{
				firstPoint = mousePoint;
				firstPointConnection = new Connection(firstPoint.x(), firstPoint.y());
				scene->addItem(firstPointConnection);
				roomStageCycle = false;
			}else
			{
				cout << "First point x=" << firstPoint.x() << " y=" << firstPoint.y() << endl;
				cout << "2nd point x=" << mousePoint.x() << " y=" << mousePoint.y() << endl;
				scene->removeItem(firstPointConnection);
				delete firstPointConnection;
				firstPointConnection = nullptr;
				if(QLineF(firstPoint,mousePoint).length()<5*GlobalStats::GetConnRadius())
				{
					cout << "Couldn't create room, points are too close! Choose points again!"<<endl;
				}else
				{
					GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;
					Connection* c1 = new Connection(firstPoint.x(),firstPoint.y());
					Connection* c2 = new Connection(firstPoint.x(),mousePoint.y());
					Connection* c3 = new Connection(mousePoint.x(),firstPoint.y());
					Connection* c4 = new Connection(mousePoint.x(),mousePoint.y());

					scene->addItem(c1);
					scene->addItem(c2);
					scene->addItem(c3);
					scene->addItem(c4);

					Wall* w1 = new Wall(c1,c2);
					Wall* w2 = new Wall(c2,c4);
					Wall* w3 = new Wall(c4,c3);
					Wall* w4 = new Wall(c1,c3);

					scene->addItem(w1);
					scene->addItem(w2);
					scene->addItem(w3);
					scene->addItem(w4);
				}
				roomStageCycle = true;
			}
		}
		break;

	}
}



