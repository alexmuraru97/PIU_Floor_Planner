#pragma once
#include <qgraphicsitem.h>
#include "GlobalStats.h"
#include <QGraphicsSceneMouseEvent>
#include <qtextoption.h>
#include <qtextdocument.h>

class Label;
#include "Label.h"
#include "LabelProperty.h"
class Label:public QGraphicsTextItem
{
	QColor textColor;
	QFont font;
public:
	Label(QString text,int x, int y,int textSize=20,int textWidth=60);
	void setSize(int size);
	void setBold(bool bold);
	int getFontSize();
	void updateFontData();
	void setAlignment(Qt::Alignment align);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
};

