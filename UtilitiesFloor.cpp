#include "UtilitiesFloor.h"
#include <qlayout.h>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>

UtilitiesFloor::UtilitiesFloor()
{
	//this->setStyleSheet("QWidget {background: #0000FF;}");
	QVBoxLayout* vlayout = new QVBoxLayout();
	vlayout->setAlignment(Qt::AlignTop);
	vlayout->setSpacing(40);
	QLabel* floorList = new QLabel();
	QFont font = floorList->font();
	floorList->setText("Floor list");
	font.setPointSize(14);
	floorList->setMaximumSize(200, 60);
	floorList->setStyleSheet("border:0px solid black");
	floorList->setFont(font);
	this->setLayout(vlayout);

	vlayout->addWidget(floorList);

	QPushButton* createNewFloor = new QPushButton("Create new floor");
	createNewFloor->setStyleSheet("border-width: 2px; border-radius: 20px");
	createNewFloor->setMinimumSize(100, 50);
	vlayout->addWidget(createNewFloor);

	QStringList commands = { "Plan 1", "Plan 2", "Plan 3", "Plan 4" };
	QComboBox* combo = new QComboBox(this);
	combo->addItems(commands);
	combo->setMinimumHeight(30);
	combo->setStyleSheet("border: 1px solid gray;border-radius: 10px;padding: 0 8px;");

	connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));
	vlayout->addWidget(combo);
}

void  UtilitiesFloor::indexChanged(int index)
{
	//TODO import selected floor icon
}

