#pragma once
#include "State.h"

class StateManager
{
public:
	StateManager();
	~StateManager();

	void setNextState(States aState);
	void changeState();
	State* getCurrentSate();
private:
	State* gCurrentSate;
	State* gNextState;
};

