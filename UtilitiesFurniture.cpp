#include "UtilitiesFurniture.h"


using namespace std;

UtilitiesFurniture::UtilitiesFurniture()
{
	//this->setStyleSheet("QWidget {background: #00FFFF;}");
	rowLayout = new QHBoxLayout();
	leftColumn = new QVBoxLayout();
	rightColumn = new QVBoxLayout();
	panelHolderLayout = new QVBoxLayout();
	panelHolderLayout->setAlignment(Qt::AlignTop);
	panelHolderLayout->setSpacing(40);

	this->setLayout(panelHolderLayout);

	/*QStringList commands = { "Living room furniture", "kitchen furniture", "Dining room furniture", "Bedroom furniture","Bathroom furniture","Hallway furniture" };
	QComboBox* combo = new QComboBox(this);
	combo->addItems(commands);
	combo->setStyleSheet("border: 1px solid gray;border-radius: 10px;padding: 0 8px;");
	combo->setMinimumHeight(30);

	combo->setPlaceholderText(QStringLiteral("--Select Room Type--"));
	combo->setCurrentIndex(-1);

	connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));
	vlayout->addWidget(combo);*/


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
	
	cout << itemCategoryComboList->currentText().toStdString() << endl;
	for (int i = 0; i < furniture->value(itemCategoryComboList->currentText()).count(); i++)
	{
		QLabel* itemLabel = new QLabel();
		itemLabel->setFixedSize(160, 120);
		itemLabel->setAlignment(Qt::AlignCenter);
		itemLabel->setPixmap(QPixmap::fromImage(furniture->value(itemCategoryComboList->currentText()).at(i).second->scaled(100, 100)));
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


