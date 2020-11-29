#pragma once
#include <qwidget.h>
#include <qlayout.h>
#include <QLabel>
#include <QDialog>
#include <QComboBox>
#include <QDir>
#include <iostream>
#include <QPixmap>
#include <QScrollArea>
class UtilitiesFurniture : public QWidget
{
	Q_OBJECT
private:
	QHBoxLayout* hlayout;
	QVBoxLayout* vlayout1;
	QVBoxLayout* vlayout2;
	QVBoxLayout* vlayout;
	QMap<QString, QList<QPair<QString, QImage*>>>* furniture;
public:
	UtilitiesFurniture();
public slots:
	void indexChanged(int index);
};