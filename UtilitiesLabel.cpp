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
	setRoomType->setText("Name your room");
	setRoomType->setMaximumSize(200, 60);
	setRoomType->setStyleSheet("border:0px solid black");
	setRoomType->setFont(font);

	this->setLayout(vlayout);

	vlayout->addWidget(setRoomType);

	HandlerButton* addLabel = new HandlerButton(GlobalStats::SceneOperationType::INSERT_LABEL, nullptr, this);
	addLabel->setText("Add Label");
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