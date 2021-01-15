#include "UtilitiesGrid.h"

UtilitiesGrid::UtilitiesGrid()
{
	this->setLayout(&layout);
}

void UtilitiesGrid::ClearWidgets()
{
	while (layout.count() > 0)
	{
		delete layout.takeAt(0);
	}
}

void UtilitiesGrid::AddWidget(QWidget* widget)
{
	layout.addWidget(widget);
}
