#pragma once
#include <QGraphicsView>
#include <qwidget.h>
#include <QMouseEvent>
#include <QKeyEvent>
using namespace std;
class DrawPanelWidget :public QWidget
{
private:
	QGraphicsView* view;
	QGraphicsScene* scene;
public:
	DrawPanelWidget();
	void resizeEvent(QResizeEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;
};

