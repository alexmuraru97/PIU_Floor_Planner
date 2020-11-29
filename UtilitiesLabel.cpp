#include "UtilitiesLabel.h"
#include <qlayout.h>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>


UtilitiesLabel::UtilitiesLabel()
{
	QVBoxLayout* vlayout = new QVBoxLayout();
	vlayout->setAlignment(Qt::AlignTop);
	vlayout->setSpacing(40);

	QLabel* setRoomType = new QLabel();
	QFont font = setRoomType->font();
	font.setPointSize(14);
	setRoomType->setText("Set Room Type");
	setRoomType->setMaximumSize(200, 60);
	setRoomType->setStyleSheet("border:0px solid black");
	setRoomType->setFont(font);

	this->setLayout(vlayout);

	vlayout->addWidget(setRoomType);

	QStringList commands = { "Bathroom", "Living", "Dining Room", "Bedroom","Kitchen","Hallway" };
	QComboBox* combo = new QComboBox(this);
	combo->addItems(commands);
	combo->setMinimumHeight(30);
	combo->setStyleSheet("border: 1px solid gray;border-radius: 10px;padding: 0 8px;");
	connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));
	vlayout->addWidget(combo);

	QPushButton* addLabel = new QPushButton("Add Label");
	addLabel->setStyleSheet("border-width: 2px; border-radius: 20px");
	addLabel->setMinimumSize(100, 50);
	vlayout->addWidget(addLabel);

	QPushButton* drawDimension = new QPushButton("Draw dimension");
	drawDimension->setStyleSheet("border-width: 2px; border-radius: 20px");
	drawDimension->setMinimumSize(100, 50);
	vlayout->addWidget(drawDimension);

}
void  UtilitiesLabel::indexChanged(int index)
{
	//TODO show the furniture for the selected room 
}