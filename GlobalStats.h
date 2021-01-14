#pragma once
#include <QGraphicsScene>
#include "UtilitiesGrid.h"
#include "UtilityPanelWidget.h"

class GlobalStats
{
	static int wallWidth;
	static int gridStep;
	static int connRadius;
	static QGraphicsScene* scene;
	static bool isShowingConnections;
	static UtilitiesGrid* propertyPanelHolder;
	static int propertyPanelIndex;
	static int oldPanelIndex;
	static bool togglePropertyStatus;
	static UtilityPanelWidget* leftMenuPanel;
	static QString doorIcon;
	static QString windowIcon;
public:
	enum class SceneOperationType { NONE, INSERT_WALL, INSERT_DOOR, INSERT_WINDOW, INSERT_LABEL,DELETE,INSERT_ROOM };
	static SceneOperationType currentOperation;
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
	static void SetPropertyPanelIndex(int idx);
	static int GetPropertyPanelIndex();
	static void SetLeftMenuPanel(UtilityPanelWidget* panel);
	static void ToggleOnPropertyMenu();
	static void ToggleOffPropertyMenu();
	static void SetDoorIcon(QString path);
	static QString GetDoorIcon();
	static void SetWindowIcon(QString path);
	static QString GetWindowIcon();
	static bool GetTogglePropertyStatus();
};