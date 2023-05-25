#pragma once

class Widget;
class Mediator {
public:
	Mediator() {}
	virtual ~Mediator() {}

	virtual void buttonChanged(Widget *) = 0;
};