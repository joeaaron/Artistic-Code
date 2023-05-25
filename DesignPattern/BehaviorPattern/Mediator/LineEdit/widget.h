#pragma once

#include "mediator.h"

class Widget {
public:
	Widget(Mediator *mediator) : m_mediator(mediator) {}
	virtual ~Widget() {}

	virtual void Click() {
		m_mediator->buttonChanged(this);
	}

private:
	Mediator *m_mediator;
};
