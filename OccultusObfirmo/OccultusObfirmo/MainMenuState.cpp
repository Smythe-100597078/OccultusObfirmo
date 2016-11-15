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

States MainMenuState::HandleEvent()
{

	States result = STATE_MAINMENU;
	bool selected = false;

	do {
		while (SDL_PollEvent(aEvent) != 0)
		{
			if (aEvent->type == SDL_QUIT)
			{
				result = STATE_EXIT;
				selected = true;
			}
			else
			{
				if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(btnPlay->getRectangle()))
				{
					result = STATE_GAMEPLAY;
					selected = true;
				}
				else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(btnCreate->getRectangle()))
				{
					result = STATE_ABOUT;
					selected = true;
				}
				else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(btnInstruct->getRectangle()))
				{
					result = STATE_INSTRUCTIONS;
					selected = true;
				}
				else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(btnExit->getRectangle()))
				{
					result = STATE_EXIT;
					selected = true;
				}
			}

		}
	} while (!selected);

	return result;
}
