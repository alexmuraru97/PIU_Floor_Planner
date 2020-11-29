#pragma once
#include <QGraphicsScene>
class GlobalStats
{
private:
	static int wallWidth;
	static int gridStep;
	static int connRadius;
	static QGraphicsScene* scene;
public:
	static int GetWallWidth();
	static void SetWallWidth(int width);
	static int GetGridStep();
	static void SetGridStep(int step);
	static int GetConnRadius();
	static void SetConnRadius(int radius);
	static QGraphicsScene* GetGraphicsScene();
	static void SetGraphicsScene(QGraphicsScene* scene);
};