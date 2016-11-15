#include "stdafx.h"
#include "GamePlay.h"


GamePlay::GamePlay()
{
	gId = States::STATE_INSTRUCTIONS;
	hero = new Player("Game Hero", "Hero.png", 325, 540, 50, 50);
	btnBack = new Button("Button Back", "BackBtn.bmp", 715, 560, 50, 25);
	enemy = new Enemy("Lvl1 Enemy", "Enemy1.png", 295, 0, 88, 105);
	project = new Projectile("Projectile", "Magic.png", hero->getX(), hero->getY(), 15, 14);
	keyImage = new Button("Key","key.png", 50, 250, 25, 25);
	key = new Item("Key", "..It may unlock something", new std::string[2]{ "key","key" });
	
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
	
	if (enemy->getAlive())
	{
		enemy->Display(aSurface);
	}
	if (gFunctions->check_collision(keyImage->getRectangle(), hero->getRectangle()))
	{
		hero->inv->Put(key);
		keyImage->setX(709);
		keyImage->setY(160);
		std::cout << "You picked up a " + key->Name() << std::endl;
	}


	
	if (hero->getAlive())
	{
		hero->Display(aSurface);

	}
	
	if (project->getFiredStatus() && project->getAlive())
	{
		int dy = project->getY() - 0.1;
		while (project->getY() != 20)
		{
			project->setY(dy--);
		}
		project->Display(aSurface);
		
	}

	if (gFunctions->check_collision(project->getRectangle(), enemy->getRectangle()) && enemy->getAlive())
	{
		project->setFiredStatus(false);
		int x = enemy->fHealth->getHealth();
		enemy->fHealth->setHealth(x - 1);
		if (enemy->fHealth->getHealth() <= 0)
		{
			enemy->setAlive(false);
		}
		project->setAlive(false);

	}
	if (gFunctions->check_collision(hero->getRectangle(), enemy->getRectangle()) && enemy->getAlive() && hero->getAlive())
	{ 
		enemy->setCollided(true);
		
		if (hero->fHealth->getHealth() > 0)
		{
			hero->removelife();
			enemy->setX(295);
			enemy->setY(0);

		}
		else if(hero->fHealth->getHealth() <= 0)
		{
			hero->setAlive(false);
		}
		
		if (hero->fHealth->getHealth() > 0)
		{
			std::cout << "You have " + std::to_string(hero->fHealth->getHealth()) + " lives remaining" << std::endl;
		}
		if(hero->fHealth->getHealth() == 0 && hero->getAlive() == false)
		{
			std::cout << "You have died" << std::endl;
		}
	}
	enemy->ChasePlayer(enemy, hero);
	btnBack->Display(aSurface);
	keyImage->Display(aSurface);
}

States GamePlay::HandleEvent()
{
	States result = STATE_NULL;
	std::cout << IMG_GetError() << std::endl;
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
				if(hero->getY() >= 20)
				{
					int dy = hero->getY() - 20;
					hero->setY(dy--);
				}
			}
			if (gFunctions->buttonDown(aEvent, SDLK_DOWN))
			{
				if (hero->getY() <= 580-hero->getH())
				{
					int dy = hero->getY() + 20;
					hero->setY(dy++);
				}
			}
			if (gFunctions->buttonDown(aEvent, SDLK_LEFT))
			{
				if (hero->getX() >= 10)
				{
					int dx = hero->getX() - 20;
					hero->setX(dx--);
				}
			}
			if (gFunctions->buttonDown(aEvent, SDLK_RIGHT))
			{
				if (hero->getX() <= 575+hero->getW())
				{
					int dx = hero->getX() + 20;
					hero->setX(dx++);
				}
			}
			if (hero->fHealth->getHealth() == 0)
			{
				result = States::STATE_GAME_OVER;
				selected = true;

			}
			if (gFunctions->buttonDown(aEvent, SDLK_SPACE))
			{
					project->setFiredStatus(true);
					project->setAlive(true);
			}

		}
	} while (!selected);

	return result;
}
