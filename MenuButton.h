#pragma once
#include <qpushbutton.h>
#include  <QStackedWidget>
#include "GlobalStats.h"
class MenuButton :public QPushButton
{
private:
	QStackedWidget* panel;
	int index;
public:
	MenuButton(QStackedWidget* panel, int index, QWidget* parent = nullptr);
	void enterEvent(QEvent* event) override;
	void leaveEvent(QEvent* event) override;
	bool hitButton(const QPoint& pos) const override;
};

