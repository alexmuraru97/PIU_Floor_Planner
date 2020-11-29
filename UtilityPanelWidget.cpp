#include "UtilityPanelWidget.h"
#include "UtilitiesFloor.h"
#include "UtilitiesDraw.h"
#include "UtilitiesFurniture.h"
#include "UtilitiesLabel.h"
#include "UtilitiesGrid.h"
#include <QPushButton>
UtilityPanelWidget::UtilityPanelWidget():QStackedWidget()
{
	this->setStyleSheet("border: 1px solid black");
	this->setFixedWidth(400);
	this->addWidget(new UtilitiesFloor());
	this->addWidget(new UtilitiesDraw());
	this->addWidget(new UtilitiesLabel());
	this->addWidget(new UtilitiesFurniture());
	this->addWidget(new UtilitiesGrid());
	this->setCurrentIndex(4);
}
