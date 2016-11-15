#include "stdafx.h"
#include "AboutState.h"


AboutState::AboutState()
{
	gId = States::STATE_ABOUT;
	btnBack = new Button("Button Back", "BackBtn.bmp", 10, 10, 100, 50);
	
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

States AboutState::HandleEvent()
{
	States result = STATE_NULL;
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
				if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(btnBack->getRectangle()))
				{
					result = STATE_MAINMENU;
					selected = true;
				}
			}
		}
	} while (!selected);

	return result;
}
