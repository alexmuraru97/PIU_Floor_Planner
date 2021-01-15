#include "GlobalStats.h"

int GlobalStats::wallWidth = 1;
int GlobalStats::gridStep = 1;
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
QString GlobalStats::furnitureIcon = "";
bool GlobalStats::togglePropertyStatus = false;
GlobalStats::SceneOperationType GlobalStats::currentOperation = GlobalStats::SceneOperationType::NONE;

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

UtilitiesGrid* GlobalStats::GetPropertyPanelHolder()
{
	return GlobalStats::propertyPanelHolder;
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

void GlobalStats::ExportProject()
{
	if (scene->views().size() > 0)
	{
		QString fileName = QFileDialog::getSaveFileName(scene->views().front(), "Save image", QDir::currentPath()+QString("Project.png"), "PNG (*.png);;JPEG (*.JPEG)");
		if (!fileName.isNull())
		{
			QPixmap pixMap = scene->views().front()->grab();
			pixMap.save(fileName);
		}
	}
	else
	{
		std::cout << "Cannot export project, view not found";
	}
}

void GlobalStats::ClearScene()
{
	QMessageBox msgBox;
	msgBox.setText("Are you sure you want to clear the scene?");
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Cancel);
	int ret = msgBox.exec();
	if(ret==QMessageBox::Ok)
	{
		while (scene->items().size() > 0)
		{
			QGraphicsItem* item = scene->items().front();
			scene->removeItem(item);
		}
	}
}

void GlobalStats::SetFurnitureIcon(QString path)
{
	GlobalStats::furnitureIcon = path;
}

QString GlobalStats::GetFurnitureIcon()
{
	return GlobalStats::furnitureIcon;
}

GlobalStats::SceneOperationType GlobalStats::GetOperationType()
{
	return GlobalStats::currentOperation;
}

void GlobalStats::SetOperationType(SceneOperationType op)
{
	GlobalStats::currentOperation = op;
	if(op!=SceneOperationType::INSERT_FURNITURE)
	{
		GlobalStats::furnitureIcon = "";
	}
}

void GlobalStats::ToggleOnPropertyMenu(QWidget* propertyWidget)
{
	GlobalStats::leftMenuPanel->setCurrentIndex(GlobalStats::propertyPanelIndex);
	GlobalStats::togglePropertyStatus = true;
	if(propertyWidget!=nullptr)
	{
		propertyPanelHolder->AddWidget(propertyWidget);
	}
	
}

void GlobalStats::ToggleOffPropertyMenu()
{
	GlobalStats::leftMenuPanel->setCurrentIndex(GlobalStats::oldPanelIndex);
	GlobalStats::togglePropertyStatus = false;
	propertyPanelHolder->ClearWidgets();
	
}
