#include "stdafx.h"
#include "AboutState.h"


AboutState::AboutState()
{
	gId = States::STATE_ABOUT;
	btnBack = new Button("Button Back", "BackBtn.bmp", 700, 550, 100, 50);
}


AboutState::~AboutState()
{
}

void AboutState::Display(SDL_Surface* aSurface)
{
	// Display the background
	SDL_Surface* background = NULL;
	background = SDL_LoadBMP("Resources/Creator.bmp");
	SDL_BlitSurface(background, NULL, aSurface, NULL);
	SDL_FreeSurface(background);
	// Display the button
	btnBack->Display(aSurface);
}

States AboutState::HandleEvent(SDL_Event* aEvent)
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
		result = States::STATE_ABOUT;
	}

	return result;
}
