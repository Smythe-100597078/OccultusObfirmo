#include "stdafx.h"
#include "MainMenuState.h"


MainMenuState::MainMenuState()
{
	gId = States::STATE_MAINMENU;
	btnPlay = new Button("Button Play", "StartBtn.bmp", 358 ,145, 75, 45);
	btnInstruct = new Button("Button Instructions", "InstructionsBtn.bmp", 300, 215, 190, 40);
	btnCreate = new Button("Button Creator", "CreatorBtn.bmp", 335, 280, 115 ,45);
	btnExit = new Button("Button Exit", "ExitBtn.bmp", 358, 345, 75, 45);


}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Display(SDL_Surface* aSurface)
{
	// Display the background image
	SDL_Surface* background = NULL;
	background = SDL_LoadBMP("Resources/MainMenu.bmp");
	SDL_BlitSurface(background, NULL, aSurface, NULL);
	
	SDL_FreeSurface(background);
	
	// Display the buttons
	btnPlay->Display(aSurface);
	btnInstruct->Display(aSurface);
	btnCreate->Display(aSurface);
	btnExit->Display(aSurface);
	
}

States MainMenuState::HandleEvent(SDL_Event* aEvent)
{
	States result;
	int x, y;
	SDL_GetMouseState(&x, &y);

	if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnPlay->getRectangle()))
	{
		result = States::STATE_GAMEPLAY;
	}
	else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnCreate->getRectangle()))
	{
		result = States::STATE_ABOUT;
	}
	else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnExit->getRectangle()))
	{
		result = States::STATE_EXIT;
	}
	else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnInstruct->getRectangle()))
	{
		result = States::STATE_INSTRUCTIONS;
	}
	else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnPlay->getRectangle()))
	{
		result = States::STATE_GAMEPLAY;
	}
	else
	{
		result = States::STATE_MAINMENU;
	}

	return result;
}
