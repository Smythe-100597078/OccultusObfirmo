#include "stdafx.h"
#include "StateManager.h"
#include "MainMenuState.h"
#include "AboutState.h"
#include "InstructState.h"
#include "GameOverState.h"
#include "GamePlay.h"


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
	case States::STATE_INSTRUCTIONS:
		gNextState = new InstructState();
		break;
	case States::STATE_GAMEPLAY:
		gNextState = new GamePlay();
		break;
	case States::STATE_GAME_OVER:
		gNextState = new GameOverState();
		break;
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