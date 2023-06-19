#pragma once

#include <time.h>
#include <string>
#include "memento.h"

class Originator {
public:
	Originator() : m_state("NULL") {
		time(&m_uuid);
	}

	void setState(string state) {
		m_state = state;
	}

	void showState() {
		cout << "Current state : " << m_state << endl;
	}

	Memento *createMemento() {
		cout << "backup state : " << m_state << endl;
		return new Memento(m_state, std::to_string(m_uuid));
	}

	void setMemento(Memento* memento) {
		if (memento) {
			bool success = memento->getState(m_state, std::to_string(m_uuid));
			if (success)
				cout << "Undo Success" << endl;
			else
				cout << "Undo Failure" << endl;
		}
	}

private:
	string m_state;
	time_t m_uuid;
};