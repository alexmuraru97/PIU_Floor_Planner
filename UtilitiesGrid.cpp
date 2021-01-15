#include "UtilitiesGrid.h"

UtilitiesGrid::UtilitiesGrid()
{
	this->setLayout(&layout);
}

void UtilitiesGrid::ClearWidgets()
{
	qDeleteAll(this->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
}

void UtilitiesGrid::AddWidget(QWidget* widget)
{
	ClearWidgets();
	layout.addWidget(widget);
}
