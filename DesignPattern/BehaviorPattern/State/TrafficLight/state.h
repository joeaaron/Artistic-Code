#pragma once

class Context;

class State
{
public:
	State();
	virtual ~State();

	int Handle(Context *context);
	void setNextState(State *state);

private:
	virtual int doSomething() = 0;

private:
	State *m_nextState;
};