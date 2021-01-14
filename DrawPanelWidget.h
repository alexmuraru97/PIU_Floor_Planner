#pragma once
#include <QGraphicsView>
#include <qwidget.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <iostream>
#include "Wall.h"
#include "GlobalStats.h"
#include "CustomGraphicsView.h"
#include "Door.h"
#include "Furniture.h"
using namespace std;
class DrawPanelWidget :public QWidget
{
private:
	bool roomStageCycle;
	QGraphicsView* view;
	QGraphicsScene* scene;
public:
	DrawPanelWidget();
	void resizeEvent(QResizeEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
};

