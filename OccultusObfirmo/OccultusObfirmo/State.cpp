#include "stdafx.h"
#include "State.h"


State::State()
{
	gFunctions = new Functions();
}

State::State(States aID)
{
	gId = aID;
}


State::~State()
{
}

States State::getID()
{
	return gId;
}

void State::Update()
{
}
