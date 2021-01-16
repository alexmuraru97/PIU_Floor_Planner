#include "WallProperty.h"

WallProperty::WallProperty(Wall* wall, QWidget* parent):QWidget(parent)
{
	this->wall = wall;
	this->setLayout(&layout);
	layout.setAlignment(Qt::AlignTop|Qt::AlignHCenter);
	layout.setSpacing(40);
	
	widthSlider.setOrientation(Qt::Horizontal);
	widthSliderLabel.setStyleSheet("border:none");
	widthSliderLabel.setText(QString("Wall Width (current:") + QString(std::to_string(GlobalStats::GetWallWidth()).c_str()) + QString(")"));
	widthSlider.setMinimum(1);
	widthSlider.setMaximum(10);
	layout.addWidget(&widthSliderLabel);
	layout.addWidget(&widthSlider);
	connect(&widthSlider, &QSlider::valueChanged, this, &WallProperty::wallWidthSetValue);

	gridSnapSlider.setOrientation(Qt::Horizontal);
	gridSnapLabel.setStyleSheet("border:none");
	gridSnapLabel.setText(QString("Grid Snap Size (current:") + QString(std::to_string(GlobalStats::GetGridStep()).c_str()) + QString(")"));
	gridSnapSlider.setMinimum(1);
	gridSnapSlider.setMaximum(50);
	layout.addWidget(&gridSnapLabel);
	layout.addWidget(&gridSnapSlider);
	connect(&gridSnapSlider, &QSlider::valueChanged, this, &WallProperty::gridSnapSetValue);
}

void WallProperty::gridSnapSetValue(int value)
{
	GlobalStats::SetGridStep(value);
	gridSnapLabel.setText(QString("Grid Snap Size (current:") + QString(std::to_string(GlobalStats::GetGridStep()).c_str()) + QString(")"));
}

void WallProperty::wallWidthSetValue(int value)
{
	GlobalStats::SetWallWidth(value);
	widthSliderLabel.setText(QString("Wall Width (current:") + QString(std::to_string(GlobalStats::GetWallWidth()).c_str()) + QString(")"));
	for (QGraphicsItem* item : GlobalStats::GetGraphicsScene()->items())
	{
		if (dynamic_cast<Wall*>(item) != nullptr)
		{
			dynamic_cast<Wall*>(item)->updatePositions();
		}
	}
}
