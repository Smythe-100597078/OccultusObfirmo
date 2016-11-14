#include "stdafx.h"
#include "InstructState.h"


InstructState::InstructState()
{
	gId = States::STATE_INSTRUCTIONS;
	btnBack = new Button("Button Back", "BackBtn.bmp", 10, 10, 100, 50);
}


InstructState::~InstructState()
{
}

void InstructState::Display(SDL_Surface* aSurface)
{
	// Display the background
	SDL_Surface* background = NULL;
	background = SDL_LoadBMP("Resources/Instructions.bmp");
	SDL_BlitSurface(background, NULL, aSurface, NULL);
	SDL_FreeSurface(background);

	// Display the button
	btnBack->Display(aSurface);
}

States InstructState::HandleEvent(SDL_Event* aEvent)
{
	States result;
	int x, y;
	SDL_GetMouseState(&x, &y);

	if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnBack->getRectangle()))
	{
		result = States::STATE_MAINMENU;
	}
	else
	{
		result = States::STATE_INSTRUCTIONS;
	}

	return result;
}
