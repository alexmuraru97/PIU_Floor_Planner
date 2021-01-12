#pragma once
#include <QGraphicsScene>
#include "UtilitiesGrid.h"
class GlobalStats
{
private:
	static int wallWidth;
	static int gridStep;
	static int connRadius;
	static QGraphicsScene* scene;
	static bool isShowingConnections;
	static QGraphicsItem* activeItem;
	static UtilitiesGrid* propertyPanelHolder;
	static int oldPanelIndex;
public:
	static QPoint mousePosition;
	static int GetWallWidth();
	static void SetWallWidth(int width);
	static int GetGridStep();
	static void SetGridStep(int step);
	static int GetConnRadius();
	static void SetConnRadius(int radius);
	static QGraphicsScene* GetGraphicsScene();
	static void SetGraphicsScene(QGraphicsScene* scene);
	static bool GetIsShowingConnections();
	static void SetIsShowingConnections(bool val);
	static void ShowPropertyPanel(QWidget* pPanel);
	static void SetPropertyPanelHolder(UtilitiesGrid* uGrid);
	static void SetOldPanelIndex(int idx);
	static int GetOldPanelIndex();
};