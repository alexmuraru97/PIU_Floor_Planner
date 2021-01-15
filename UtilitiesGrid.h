#pragma once
#include <qboxlayout.h>
#include <qwidget.h>
class UtilitiesGrid : public QWidget
{
private:
	QWidget* data;
	QVBoxLayout layout;
public:
	UtilitiesGrid();
	void ClearWidgets();
	void AddWidget(QWidget* widget);
};
