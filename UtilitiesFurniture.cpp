#include "UtilitiesFurniture.h"


using namespace std;

UtilitiesFurniture::UtilitiesFurniture()
{
	//this->setStyleSheet("QWidget {background: #00FFFF;}");
	hlayout = new QHBoxLayout();
	vlayout1 = new QVBoxLayout();
	vlayout2 = new QVBoxLayout();
	vlayout = new QVBoxLayout();
	vlayout->setAlignment(Qt::AlignTop);
	vlayout->setSpacing(40);

	this->setLayout(vlayout);

	QStringList commands = { "Living room furniture", "kitchen furniture", "Dining room furniture", "Bedroom furniture","Bathroom furniture","Hallway furniture" };
	QComboBox* combo = new QComboBox(this);
	combo->addItems(commands);
	combo->setStyleSheet("border: 1px solid gray;border-radius: 10px;padding: 0 8px;");
	combo->setMinimumHeight(30);

	combo->setPlaceholderText(QStringLiteral("--Select Room Type--"));
	combo->setCurrentIndex(-1);

	connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));
	vlayout->addWidget(combo);


	QDir directory = QDir("./Assets/Furniture");

	furniture = new QMap<QString, QList<QPair<QString, QImage*>>>();

	for (auto const& data : directory.entryInfoList({}, QDir::AllDirs | QDir::NoSymLinks | QDir::NoDotAndDotDot)) {
		QString path = data.absoluteFilePath();
		QString category = path.split("/").takeLast();
		QDir dir = QDir(path);

		QStringList images = dir.entryList(QStringList() << "*.png" << "*.PNG", QDir::Files);
		//cout << path.toStdString() << endl;
		QList<QPair<QString, QImage*>> furnitureElements;
		foreach(QString filename, images) {

			furnitureElements.append(QPair<QString, QImage*>(filename, new QImage(path + "/" + filename)));

		}
		furniture->insert(category, furnitureElements);

	}




}

void  UtilitiesFurniture::indexChanged(int index)
{
	QLayoutItem* child;
	while ((child = vlayout1->takeAt(0)) != nullptr)
	{
		if (child->widget() != nullptr)
		{
			delete child->widget();
		}
	}
	QLayoutItem* child2;
	while ((child2 = vlayout2->takeAt(0)) != nullptr)
	{
		if (child2->widget() != nullptr)
		{
			delete child2->widget();
		}
	}



	switch (index)
	{
	case 0:
		for (int i = 0; i < furniture->value("Living").count(); i++)
		{
			QLabel* l = new QLabel();
			l->setFixedSize(160, 120);
			l->setAlignment(Qt::AlignCenter);
			l->setPixmap(QPixmap::fromImage(furniture->value("Living").at(i).second->scaled(100, 100)));
			if (i % 2 == 0)
				vlayout1->addWidget(l);
			else
				vlayout2->addWidget(l);

		}
		break;
	case 1:
		for (int i = 0; i < furniture->value("Kitchen").count(); i++)
		{
			QLabel* l = new QLabel();
			l->setFixedSize(160, 120);
			l->setAlignment(Qt::AlignCenter);
			l->setPixmap(QPixmap::fromImage(furniture->value("Kitchen").at(i).second->scaled(100, 100)));
			if (i % 2 == 0)
				vlayout1->addWidget(l);
			else
				vlayout2->addWidget(l);

		}
		break;
	case 2:
		for (int i = 0; i < furniture->value("Dining").count(); i++)
		{
			QLabel* l = new QLabel();
			l->setFixedSize(160, 120);
			l->setAlignment(Qt::AlignCenter);
			l->setPixmap(QPixmap::fromImage(furniture->value("Dining").at(i).second->scaled(100, 100)));
			if (i % 2 == 0)
				vlayout1->addWidget(l);
			else
				vlayout2->addWidget(l);

		}
		break;
	case 3:
		for (int i = 0; i < furniture->value("Bedroom").count(); i++)
		{
			QLabel* l = new QLabel();
			l->setFixedSize(160, 120);
			l->setAlignment(Qt::AlignCenter);
			l->setPixmap(QPixmap::fromImage(furniture->value("Bedroom").at(i).second->scaled(100, 100)));
			if (i % 2 == 0)
				vlayout1->addWidget(l);
			else
				vlayout2->addWidget(l);

		}
		break;
	case 4:
		for (int i = 0; i < furniture->value("Bathroom").count(); i++)
		{
			QLabel* l = new QLabel();
			l->setFixedSize(160, 120);
			l->setAlignment(Qt::AlignCenter);
			l->setPixmap(QPixmap::fromImage(furniture->value("Bathroom").at(i).second->scaled(100, 100)));
			if (i % 2 == 0)
				vlayout1->addWidget(l);
			else
				vlayout2->addWidget(l);

		}
		break;
	case 5:
		for (int i = 0; i < furniture->value("Hallway").count(); i++)
		{
			QLabel* l = new QLabel();
			l->setFixedSize(160, 120);
			l->setAlignment(Qt::AlignCenter);
			l->setPixmap(QPixmap::fromImage(furniture->value("Hallway").at(i).second->scaled(100, 100)));
			if (i % 2 == 0)
				vlayout1->addWidget(l);
			else
				vlayout2->addWidget(l);

		}
		break;

	default:
		break;
	}
	hlayout->addLayout(vlayout1);
	hlayout->addLayout(vlayout2);
	vlayout->addLayout(hlayout);

}


