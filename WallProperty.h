#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include "HandlerButton.h"
#include "Wall.h"
#include <QPushButton>
#include <QSlider>
#include <QLabel>
class WallProperty :public QWidget
{
	Q_OBJECT
private:
	QVBoxLayout layout;
	Wall* wall;
	QSlider widthSlider;
	QLabel widthSliderLabel;

	QSlider gridSnapSlider;
	QLabel gridSnapLabel;
public:
	WallProperty(Wall* wall, QWidget* parent = nullptr);

public slots:
	void wallWidthSetValue(int value);
	void gridSnapSetValue(int value);
};

