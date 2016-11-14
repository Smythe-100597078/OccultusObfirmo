#include "stdafx.h"
#include "MainMenuState.h"


MainMenuState::MainMenuState()
{
	gId = States::STATE_MAINMENU;
	btnPlay = new Button("Button Play", "StartBtn.bmp", 358 ,145, 75, 50);
	btnInstruct = new Button("Button Instructions", "InstructionsBtn.bmp", 20, 140, 150, 100);
	btnCreate = new Button("Button Creator", "CreatorBtn.bmp", 20, 300, 150, 100);
	btnExit = new Button("Button Exit", "ExitBtn.bmp", 20, 440, 150, 100);


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
	else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnInstruct->getRectangle()))
	{
		result = States::STATE_ABOUT;
	}
	else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnExit->getRectangle()))
	{
		result = States::STATE_EXIT;
	}
	else
	{
		result = States::STATE_MAINMENU;
	}

	return result;
}
