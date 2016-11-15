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
	State* gCurrentState;
private:
	
	State* gNextState;

protected:
	
};

