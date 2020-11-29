#include "GlobalStats.h"
int GlobalStats::wallWidth = 1;
int GlobalStats::gridStep = 10;
int GlobalStats::connRadius = 4;
bool GlobalStats::isShowingConnections = false;
QGraphicsScene* GlobalStats::scene = nullptr;

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

