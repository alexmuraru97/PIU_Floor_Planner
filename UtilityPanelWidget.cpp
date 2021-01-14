#include "UtilityPanelWidget.h"
#include "UtilitiesDraw.h"
#include "UtilitiesFurniture.h"
#include "UtilitiesLabel.h"
#include "UtilitiesGrid.h"
#include <QPushButton>
#include "GlobalStats.h"
UtilityPanelWidget::UtilityPanelWidget():QStackedWidget()
{
	this->setStyleSheet("border: 1px solid black");
	this->setFixedWidth(400);
	this->addWidget(new UtilitiesDraw());
	this->addWidget(new UtilitiesLabel());
	this->addWidget(new UtilitiesFurniture());
	UtilitiesGrid* grid = new UtilitiesGrid();
	this->addWidget(grid);
	GlobalStats::SetPropertyPanelHolder(grid);
	
	this->setCurrentIndex(0);
	GlobalStats::SetOldPanelIndex(0);
	GlobalStats::SetPropertyPanelIndex(3);
	GlobalStats::SetLeftMenuPanel(this);


}
