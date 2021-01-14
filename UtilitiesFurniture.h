#pragma once
#include <qwidget.h>
#include <qlayout.h>
#include <QLabel>
#include <QDialog>
#include <QComboBox>
#include <QDir>
#include <iostream>
#include <QPixmap>
#include <QMouseEvent>
#include "FurnitureIcon.h"

class UtilitiesFurniture : public QWidget
{
	Q_OBJECT
private:
	QHBoxLayout* rowLayout;
	QVBoxLayout* leftColumn;
	QVBoxLayout* rightColumn;
	QVBoxLayout* panelHolderLayout;
	QComboBox* itemCategoryComboList;
	QMap<QString, QList<QPair<QString, QImage*>>>* furniture;
public:
	UtilitiesFurniture();
public slots:
	void indexChanged(int index);
};