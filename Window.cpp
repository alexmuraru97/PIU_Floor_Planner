#include "Window.h"


Window::Window(Connection* c1, Connection* c2)
{
	img = QImage(GlobalStats::GetWindowIcon());
	this->setPixmap(QPixmap::fromImage(img));

	connections[0] = c1;
	connections[1] = c2;
	c1->addWallItem(this);
	c2->addWallItem(this);
	updatePositions();
}

double Window::calculateRotation()
{
	return QLineF(connections[0]->getPoint(), connections[1]->getPoint()).angle();
}


void Window::updatePositions()
{
	this->setX(connections[0]->getPoint().x());
	this->setY(connections[0]->getPoint().y());
	this->setTransformOriginPoint(0,-GlobalStats::GetConnRadius()/2.0 );
	this->setRotation(-abs(calculateRotation()));
	this->setScale(QLineF(connections[0]->getPoint(), connections[1]->getPoint()).length() / (1.0 * this->pixmap().width()));
	
	connections[0]->show();
	connections[1]->show();
	this->update();
}


void Window::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	if(event->button()==Qt::MidButton)
	{
		event->ignore();
		return;
	}
	if (GlobalStats::GetTogglePropertyStatus())
	{
		GlobalStats::ToggleOffPropertyMenu();
	}
	else
	{
		GlobalStats::ToggleOnPropertyMenu();
	}
}


void Window::deatach()
{
	try
	{
		connections[0]->removeWallItem(this);
	}
	catch (...)
	{
		cout << "Error deataching window";
	}
	try
	{
		connections[1]->removeWallItem(this);
	}
	catch (...)
	{
		cout << "Error deataching window";
	}
}


Connection** Window::getConnections()
{
	return connections;
}


Window::~Window()
{
	deatach();
}
