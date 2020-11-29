#include "UtilitiesDraw.h"
#include <QPushButton>
#include <QLabel>
#include <qlayout.h>
UtilitiesDraw::UtilitiesDraw()
{
	//this->setStyleSheet("QWidget {background: #FF00FF;}");
	QVBoxLayout* vlayout = new QVBoxLayout();
	vlayout->setAlignment(Qt::AlignTop);
	vlayout->setSpacing(40);

	QLabel*createRoom = new QLabel();
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

	QPushButton* drawRoom = new QPushButton("Draw Room");
	drawRoom->setStyleSheet("border-width: 2px; border-radius: 20px");
	drawRoom->setMinimumSize(100, 50);
	vlayout->addWidget(drawRoom);

	QPushButton* drawWall = new QPushButton("Draw Wall");
	drawWall->setStyleSheet("border-width: 2px; border-radius: 20px");
	drawWall->setMinimumSize(100, 50);
	vlayout->addWidget(drawWall);

	vlayout->addWidget(place);

	QPushButton* placeDoor = new QPushButton("Place door");
	placeDoor->setStyleSheet("border-width: 2px; border-radius: 20px");
	placeDoor->setMinimumSize(100, 50);
	vlayout->addWidget(placeDoor);

	QPushButton* placeWindows = new QPushButton("Place window");
	placeWindows->setStyleSheet("border-width: 2px; border-radius: 20px");
	placeWindows->setMinimumSize(100, 50);
	vlayout->addWidget(placeWindows);

}
