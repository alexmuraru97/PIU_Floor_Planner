#include "GlobalStats.h"
int GlobalStats::wallWidth = 2;
int GlobalStats::gridStep = 2;
int GlobalStats::connRadius = 4;
bool GlobalStats::isShowingConnections = false;
QGraphicsScene* GlobalStats::scene = nullptr;
QPoint GlobalStats::mousePosition(0,0);

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


