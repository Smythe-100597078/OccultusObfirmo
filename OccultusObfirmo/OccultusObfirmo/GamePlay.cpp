#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay()
{
	gId = States::STATE_INSTRUCTIONS;
	hero = new Player("Game Hero","Hero.png", 325, 540, 50, 50);
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

States GamePlay::HandleEvent()
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

			if (gFunctions->buttonDown(aEvent, SDLK_UP))
			{
				int dy = hero->getY();
				hero->setY(dy--);
				std::cout << dy << std::endl;
			}


		}
	} while (!selected);

	return result;
}
