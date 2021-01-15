#pragma once
#include <QPushButton>
#include "GlobalStats.h"
class HandlerButton:public QPushButton
{
private:
	void (*handlingFunction)();
	GlobalStats::SceneOperationType operationType;
public:
	HandlerButton(GlobalStats::SceneOperationType op, void (*fct)()=nullptr, QWidget* parent=nullptr);
	void enterEvent(QEvent* event) override;
	void leaveEvent(QEvent* event) override;
	bool hitButton(const QPoint& pos) const override;
	~HandlerButton();
};

