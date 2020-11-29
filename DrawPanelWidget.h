#pragma once
#include <QGraphicsView>
#include <qwidget.h>
#include <QWheelEvent>
using namespace std;
class DrawPanelWidget :public QWidget
{
private:
	QGraphicsView* view;
	QGraphicsScene* scene;
public:
	DrawPanelWidget();
	void resizeEvent(QResizeEvent* event) override;

	
};

