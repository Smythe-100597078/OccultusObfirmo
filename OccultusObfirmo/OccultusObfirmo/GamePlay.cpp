#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay()
{
	gId = States::STATE_INSTRUCTIONS;
	hero = new Player("Game Hero","Hero.bmp", 400, 300, 50, 50);
	btnBack = new Button("Button Back", "BackBtn.bmp", 715, 560, 50, 25);
}


GamePlay::~GamePlay()
{
}

void GamePlay::Display(SDL_Surface* aSurface)
{
	// Display the background
	SDL_Surface* background = NULL;
	background = SDL_LoadBMP("Resources/Level1.bmp");
	SDL_BlitSurface(background, NULL, aSurface, NULL);
	SDL_FreeSurface(background);

	hero->Display(aSurface);
	btnBack->Display(aSurface);
}

States GamePlay::HandleEvent(SDL_Event* aEvent)
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
		result = States::STATE_GAMEPLAY;
	}
	return result;
}
