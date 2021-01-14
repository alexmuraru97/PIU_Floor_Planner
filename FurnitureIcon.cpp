#include "FurnitureIcon.h"

FurnitureIcon::FurnitureIcon(QString path, QImage* img, QWidget* parent) :QLabel(parent)
{
	textData = path;
	furnitureIconImg = img;
	this->setPixmap(QPixmap::fromImage(img->scaled(100, 100)));
}

void FurnitureIcon::mousePressEvent(QMouseEvent* event)
{
	std::cout <<"Selected-> " <<textData.toStdString() << std::endl;
	GlobalStats::SetFurnitureIcon(textData);
	GlobalStats::SetOperationType(GlobalStats::SceneOperationType::INSERT_FURNITURE);
}
