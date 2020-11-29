
#pragma once
#include <qwidget.h>
class UtilitiesLabel : public QWidget
{
Q_OBJECT
public:
	UtilitiesLabel();
public slots:
	void indexChanged(int index);
};