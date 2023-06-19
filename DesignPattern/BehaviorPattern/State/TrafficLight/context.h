#pragma once

#include <list>

class State;

class Context
{
public:
	Context();
	~Context();

	int Handle();

private:
	friend class State;
	void setState(State *state);

private:
	std::list<State *> m_allStates;
	State *m_currentState;
};
