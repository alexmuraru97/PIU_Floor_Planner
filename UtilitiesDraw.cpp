#include "UtilitiesDraw.h"
#include <QPushButton>
#include <QLabel>
#include <qlayout.h>
UtilitiesDraw::UtilitiesDraw()
{
	QVBoxLayout* vlayout = new QVBoxLayout();
	vlayout->setAlignment(Qt::AlignTop);
	vlayout->setSpacing(40);

	
	QLabel* createRoom = new QLabel();
	QFont font = createRoom->font();
	font.setPointSize(14);
	createRoom->setText("Create room");
	createRoom->setMaximumSize(160,60);
	createRoom->setStyleSheet("border:0px solid black");
	createRoom->setFont(font);
	
	
	QLabel* place = new QLabel();
	QFont font1 = place->font();
	font1.setPointSize(14);
	place->setText("Place");
	place->setMaximumSize(160, 60);
	place->setStyleSheet("border:0px solid black");
	place->setFont(font1);
	

	this->setLayout(vlayout);

	vlayout->addWidget(createRoom);

	HandlerButton* drawRoom = new HandlerButton(GlobalStats::SceneOperationType::INSERT_ROOM,nullptr,this);
	drawRoom->setText("Draw Room");
	drawRoom->setStyleSheet("border-width: 2px; border-radius: 20px");
	drawRoom->setMinimumSize(100, 50);
	vlayout->addWidget(drawRoom);

	HandlerButton* drawWall = new HandlerButton(GlobalStats::SceneOperationType::INSERT_WALL, nullptr, this);
	drawWall->setText("Draw Wall");
	drawWall->setStyleSheet("border-width: 2px; border-radius: 20px");
	drawWall->setMinimumSize(100, 50);
	vlayout->addWidget(drawWall);


	HandlerButton* splitWall = new HandlerButton(GlobalStats::SceneOperationType::SPLIT_WALL, nullptr, this);
	splitWall->setText("Split Wall");
	splitWall->setStyleSheet("border-width: 2px; border-radius: 20px");
	splitWall->setMinimumSize(100, 50);
	vlayout->addWidget(splitWall);

	
	vlayout->addWidget(place);

	HandlerButton* placeDoor = new HandlerButton(GlobalStats::SceneOperationType::INSERT_DOOR, nullptr, this);
	placeDoor->setText("Place door");
	placeDoor->setStyleSheet("border-width: 2px; border-radius: 20px");
	placeDoor->setMinimumSize(100, 50);
	vlayout->addWidget(placeDoor);

	HandlerButton* placeWindows = new HandlerButton(GlobalStats::SceneOperationType::INSERT_WINDOW, nullptr, this);
	placeWindows->setText("Place window");
	placeWindows->setStyleSheet("border-width: 2px; border-radius: 20px");
	placeWindows->setMinimumSize(100, 50);
	vlayout->addWidget(placeWindows);



}
