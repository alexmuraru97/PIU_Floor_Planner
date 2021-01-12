#include "GlobalStats.h"
int GlobalStats::wallWidth = 2;
int GlobalStats::gridStep = 2;
int GlobalStats::connRadius = 4;
int GlobalStats::oldPanelIndex = 1;
int GlobalStats::propertyPanelIndex = 3;
bool GlobalStats::isShowingConnections = false;
UtilitiesGrid* GlobalStats::propertyPanelHolder=nullptr;
QGraphicsScene* GlobalStats::scene = nullptr;
QPoint GlobalStats::mousePosition(0,0);
UtilityPanelWidget* GlobalStats::leftMenuPanel=nullptr;
QString GlobalStats::doorIcon="";
QString GlobalStats::windowIcon="";
bool GlobalStats::togglePropertyStatus = false;

int GlobalStats::GetWallWidth()
{
	return GlobalStats::wallWidth;
}

void GlobalStats::SetWallWidth(int width)
{
	GlobalStats::wallWidth = width;
}

int GlobalStats::GetGridStep()
{
	return GlobalStats::gridStep;
}

void GlobalStats::SetGridStep(int step)
{
	GlobalStats::gridStep = step;
}

int GlobalStats::GetConnRadius()
{
	return GlobalStats::connRadius;
}

void GlobalStats::SetConnRadius(int radius)
{
	GlobalStats::connRadius = radius;
}

QGraphicsScene* GlobalStats::GetGraphicsScene()
{
	return GlobalStats::scene;
}

void GlobalStats::SetGraphicsScene(QGraphicsScene* scene)
{
	GlobalStats::scene = scene;
}

bool GlobalStats::GetIsShowingConnections()
{
	return  GlobalStats::isShowingConnections;
}

void GlobalStats::SetIsShowingConnections(bool val)
{
	GlobalStats::isShowingConnections = val;
}

void GlobalStats::SetPropertyPanelHolder(UtilitiesGrid* uGrid)
{
	GlobalStats::propertyPanelHolder = uGrid;
}

void GlobalStats::SetOldPanelIndex(int idx)
{
	GlobalStats::oldPanelIndex = idx;
}

int GlobalStats::GetOldPanelIndex()
{
	return GlobalStats::oldPanelIndex;
}

void GlobalStats::SetPropertyPanelIndex(int idx)
{
	GlobalStats::propertyPanelIndex = idx;
}

int GlobalStats::GetPropertyPanelIndex()
{
	return GlobalStats::propertyPanelIndex;
}

void GlobalStats::SetLeftMenuPanel(UtilityPanelWidget* panel)
{
	GlobalStats::leftMenuPanel = panel;
}

void GlobalStats::ToggleOnPropertyMenu()
{
	GlobalStats::leftMenuPanel->setCurrentIndex(GlobalStats::propertyPanelIndex);
	GlobalStats::togglePropertyStatus = true;
}

void GlobalStats::ToggleOffPropertyMenu()
{
	GlobalStats::leftMenuPanel->setCurrentIndex(GlobalStats::oldPanelIndex);
	GlobalStats::togglePropertyStatus = false;
}

void GlobalStats::SetDoorIcon(QString path)
{
	GlobalStats::doorIcon = path;
}

QString GlobalStats::GetDoorIcon()
{
	return GlobalStats::doorIcon;
}

void GlobalStats::SetWindowIcon(QString path)
{
	GlobalStats::windowIcon = path;
}

QString GlobalStats::GetWindowIcon()
{
	return GlobalStats::windowIcon;
}

bool GlobalStats::GetTogglePropertyStatus()
{
	return GlobalStats::togglePropertyStatus;
}


void GlobalStats::ShowPropertyPanel(QWidget* pPanel)
{
	//TODO
}
