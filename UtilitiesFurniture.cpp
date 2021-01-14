#include "UtilitiesFurniture.h"

using namespace std;

UtilitiesFurniture::UtilitiesFurniture()
{
	rowLayout = new QHBoxLayout();
	leftColumn = new QVBoxLayout();
	rightColumn = new QVBoxLayout();
	panelHolderLayout = new QVBoxLayout();
	panelHolderLayout->setAlignment(Qt::AlignTop);
	panelHolderLayout->setSpacing(40);

	this->setLayout(panelHolderLayout);

	QDir directory = QDir("./Assets/Furniture");

	furniture = new QMap<QString, QList<QPair<QString, QImage*>>>();
	QStringList commands;
	for (auto const& data : directory.entryInfoList({}, QDir::AllDirs | QDir::NoSymLinks | QDir::NoDotAndDotDot)) {
		QString path = data.absoluteFilePath();
		QString category = path.split("/").takeLast();
		commands.append(category);
		QDir dir = QDir(path);
		QStringList images = dir.entryList(QStringList() << "*.png" << "*.PNG", QDir::Files);
		
		QList<QPair<QString, QImage*>> furnitureElements;
		foreach(QString filename, images) {

			furnitureElements.append(QPair<QString, QImage*>(path + "/" + filename, new QImage(path + "/" + filename)));

		}
		furniture->insert(category, furnitureElements);
	}

	//Add category folder to dropdown list
	itemCategoryComboList = new QComboBox(this);
	itemCategoryComboList->addItems(commands);
	itemCategoryComboList->setStyleSheet("border: 1px solid gray;border-radius: 10px;padding: 0 8px;");
	itemCategoryComboList->setMinimumHeight(30);

	itemCategoryComboList->setPlaceholderText(QStringLiteral("--Select Room Type--"));
	itemCategoryComboList->setCurrentIndex(-1);
	panelHolderLayout->addWidget(itemCategoryComboList);
	connect(itemCategoryComboList, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));

	rowLayout->addLayout(leftColumn);
	rowLayout->addLayout(rightColumn);
	panelHolderLayout->addLayout(rowLayout);
}



void  UtilitiesFurniture::indexChanged(int index)
{
	QLayoutItem* child;
	while ((child = leftColumn->takeAt(0)) != nullptr)
	{
		if (child->widget() != nullptr)
		{
			delete child->widget();
		}
	}
	while ((child = rightColumn->takeAt(0)) != nullptr)
	{
		if (child->widget() != nullptr)
		{
			delete child->widget();
		}
	}
	

	for (int i = 0; i < furniture->value(itemCategoryComboList->currentText()).count(); i++)
	{
		FurnitureIcon* itemLabel = new FurnitureIcon(furniture->value(itemCategoryComboList->currentText()).at(i).first, furniture->value(itemCategoryComboList->currentText()).at(i).second);
		itemLabel->setFixedSize(160, 120);
		itemLabel->setAlignment(Qt::AlignCenter);
		if (i % 2 == 0)
		{
			leftColumn->addWidget(itemLabel);
		}
		else
		{
			rightColumn->addWidget(itemLabel);
		}
	}
	
}


