#pragma once

#include <iostream>
using namespace std;

class Memento {
public:
	~Memento() {}

private:
	friend class Originator;
	Memento(string state, const string uuid) : m_state(state), m_uuid(uuid) {}

	bool getState(string &state, string uuid) {
		if (m_uuid == uuid) {
			state = m_state;
			return true;
		}
		return false;
	}

private:
	string m_state;
	string m_uuid;
};