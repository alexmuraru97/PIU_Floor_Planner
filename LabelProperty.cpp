#include "LabelProperty.h"

LabelProperty::LabelProperty(Label* label, QWidget* parent):QWidget(parent)
{
	this->label = label;
	this->setLayout(&layout);
	layout.setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	layout.setSpacing(20);

	labelTextLabel.setStyleSheet("border:none");
	labelTextLabel.setText("Label Text:");
	labelTextLabel.setFixedHeight(40);
	labelTextLabel.setFixedWidth(300);
	labelTextLabel.setAlignment(Qt::AlignCenter);
	layout.addWidget(&labelTextLabel);
	
	labelText.setText(label->toPlainText());
	labelText.setFixedWidth(300);
	labelText.setFixedHeight(40);
	labelText.setAlignment(Qt::AlignCenter);
	layout.addWidget(&labelText);
	connect(&labelText, &QLineEdit::textChanged, this, &LabelProperty::setLabelText);



	fontSizeLabel.setStyleSheet("border:none");
	fontSizeLabel.setText("Font Size:");
	fontSizeLabel.setFixedHeight(40);
	fontSizeLabel.setFixedWidth(300);
	fontSizeLabel.setAlignment(Qt::AlignCenter);
	layout.addWidget(&fontSizeLabel);

	fontSize.setText(QString(std::to_string(label->getFontSize()).c_str()));
	fontSize.setFixedWidth(300);
	fontSize.setFixedHeight(40);
	fontSize.setAlignment(Qt::AlignCenter);
	layout.addWidget(&fontSize);
	connect(&fontSize, &QLineEdit::textChanged, this, &LabelProperty::setFontSize);
	fontSize.setValidator(new QIntValidator(0, 300));


	labelWidthLabel.setStyleSheet("border:none");
	labelWidthLabel.setText("Label Width:");
	labelWidthLabel.setFixedHeight(40);
	labelWidthLabel.setFixedWidth(300);
	labelWidthLabel.setAlignment(Qt::AlignCenter);
	layout.addWidget(&labelWidthLabel);

	labelWidth.setText(QString(std::to_string(label->textWidth()).c_str()));
	labelWidth.setFixedWidth(300);
	labelWidth.setFixedHeight(40);
	labelWidth.setAlignment(Qt::AlignCenter);
	layout.addWidget(&labelWidth);
	connect(&labelWidth, &QLineEdit::textChanged, this, &LabelProperty::setLabelWidth);
	labelWidth.setValidator(new QIntValidator(20, 10000));



	isBolded = true;
	labelBolded.setText("Bold");
	labelBolded.setStyleSheet("QPushButton{border: 1px solid gray;border-radius: 15px;padding: 15px;} QPushButton:hover{border:3px solid black}");
	layout.addWidget(&labelBolded);
	connect(&labelBolded, &QPushButton::pressed, this, &LabelProperty::toggleBold);
}

void LabelProperty::setLabelText()
{
	if(labelText.text()!="")
	{
		label->setPlainText(labelText.text());
	}
}

void LabelProperty::setFontSize()
{
	if (fontSize.text() != "")
	{
		label->setSize(fontSize.text().toInt());
	}
}

void LabelProperty::setLabelWidth()
{
	if (labelWidth.text() != "")
	{
		label->setTextWidth(labelWidth.text().toInt());
	}
}

void LabelProperty::toggleBold()
{
	isBolded = !isBolded;
	label->setBold(isBolded);
}
