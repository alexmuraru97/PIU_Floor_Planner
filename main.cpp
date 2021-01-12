#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include "UtilityPanelWidget.h"
#include "MenuWidget.h"
#include "InOutMenuWidget.h"
#include "DrawPanelWidget.h"
#include "GlobalStats.h"
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QWidget* window = new QWidget;
	window->setMinimumSize(1920, 1080);
	GlobalStats::SetDoorIcon("./Assets/DrawIcons/Door.png");
	GlobalStats::SetWindowIcon("./Assets/DrawIcons/Window.png");

	
	QHBoxLayout* hlayout = new QHBoxLayout();
	QVBoxLayout* leftPanel = new QVBoxLayout();
	QVBoxLayout* rightPanel = new QVBoxLayout();
	window->setLayout(hlayout);
	hlayout->insertLayout(0, leftPanel);
	hlayout->insertLayout(1, rightPanel);
	

	UtilityPanelWidget* utilityPanelWidget = new UtilityPanelWidget();

	MenuWidget* menuWidget = new MenuWidget(utilityPanelWidget);
	
	InOutMenuWidget* inOutMenuWidget = new InOutMenuWidget();

	DrawPanelWidget* drawPanelWidget = new DrawPanelWidget();
	

	leftPanel->addWidget(menuWidget);
	rightPanel->addWidget(inOutMenuWidget);

	leftPanel->addWidget(utilityPanelWidget);
	rightPanel->addWidget(drawPanelWidget);


	
	window->show();
	return app.exec();
}