#include "FurnitureProperty.h"

FurnitureProperty::FurnitureProperty(Furniture* furniture, QWidget* parent):QWidget(parent)
{
	this->furniture = furniture;
	this->setLayout(&layout);
	layout.setAlignment(Qt::AlignTop|Qt::AlignHCenter);
	layout.setSpacing(20);

	widthLabel.setStyleSheet("border:none");
	widthLabel.setText(QString("Furniture item Width (current:") + QString(std::to_string(furniture->pixmap().width()).c_str()) + QString(")"));
	widthTextBox.setText(QString(std::to_string(furniture->pixmap().width()).c_str()));
	widthTextBox.setFixedWidth(300);
	widthTextBox.setFixedHeight(40);
	widthLabel.setFixedHeight(40);
	widthLabel.setFixedWidth(300);
	widthLabel.setAlignment(Qt::AlignCenter);
	widthTextBox.setAlignment(Qt::AlignCenter);
	layout.addWidget(&widthLabel);
	layout.addWidget(&widthTextBox);
	connect(&widthTextBox, &QLineEdit::textChanged, this, &FurnitureProperty::furnitureWidthSetValue);

	heightLabel.setStyleSheet("border:none");
	heightLabel.setText(QString("Furniture item Height (current:") + QString(std::to_string(furniture->pixmap().height()).c_str()) + QString(")"));
	heightTextBox.setText(QString(std::to_string(furniture->pixmap().height()).c_str()));
	heightTextBox.setFixedWidth(300);
	heightTextBox.setFixedHeight(40);
	heightLabel.setFixedHeight(40);
	heightLabel.setFixedWidth(300);
	heightLabel.setAlignment(Qt::AlignCenter);
	heightTextBox.setAlignment(Qt::AlignCenter);
	layout.addWidget(&heightLabel);
	layout.addWidget(&heightTextBox);
	connect(&heightTextBox, &QLineEdit::textChanged, this, &FurnitureProperty::furnitureHeightSetValue);

	widthTextBox.setValidator(new QIntValidator(0, 10000));
	heightTextBox.setValidator(new QIntValidator(0, 10000));


	flipVertButton = new QPushButton("Flip Vertically");
	flipVertButton->setFixedHeight(60);
	flipVertButton->setStyleSheet("border-width: 2px; border-radius: 20px");
	QFont font = flipVertButton->font();
	font.setPointSize(14);
	flipVertButton->setFont(font);
	layout.addWidget(flipVertButton);
	connect(flipVertButton, &QPushButton::pressed, this, &FurnitureProperty::FlipVertically);

	flipHotizontButton = new QPushButton("Flip Horizontally");
	flipHotizontButton->setFixedHeight(60);
	flipHotizontButton->setStyleSheet("border-width: 2px; border-radius: 20px");
	QFont font1 = flipHotizontButton->font();
	font1.setPointSize(14);
	flipHotizontButton->setFont(font1);
	layout.addWidget(flipHotizontButton);
	connect(flipHotizontButton, &QPushButton::pressed, this, &FurnitureProperty::FlipHorizontally);
}

void FurnitureProperty::furnitureWidthSetValue()
{
	if(widthTextBox.text().toStdString()!="")
	{
		std::cout << widthTextBox.text().toStdString() << std::endl;
		furniture->SetWidth(widthTextBox.text().toInt());
	}
}

void FurnitureProperty::furnitureHeightSetValue()
{
	if(heightTextBox.text().toStdString()!="")
	{
		std::cout << heightTextBox.text().toStdString() << std::endl;
		furniture->SetHeight(heightTextBox.text().toInt());
	}
}

void FurnitureProperty::FlipVertically()
{
	this->furniture->FlipVertically();
}

void FurnitureProperty::FlipHorizontally()
{
	this->furniture->FlipHorizontally();
}
