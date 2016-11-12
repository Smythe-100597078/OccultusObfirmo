#include "stdafx.h"
#include "StateManager.h"
#include "MainMenuState.h"
#include "AboutState.h"


StateManager::StateManager()
{
	gCurrentState = new MainMenuState();
}

StateManager::~StateManager()
{
}

void StateManager::setNextState(States aState)
{
	switch (aState)
	{
	case States::STATE_MAINMENU:
		gNextState = new MainMenuState();
		break;
	case States::STATE_ABOUT:
		gNextState = new AboutState();
		break;
	//case States::STATE_HELP:
		//break;
	//case States::STATE_GAMEPLAY:
		//break;
	//case States::STATE_EXIT:

		//break;
	default:
		gNextState = new MainMenuState();
		break;
	}
}

void StateManager::changeState()
{
	if (gNextState != gCurrentState)
	{
		gCurrentState = gNextState;
	}
}

State* StateManager::getCurrentSate()
{
	return gCurrentState;
}