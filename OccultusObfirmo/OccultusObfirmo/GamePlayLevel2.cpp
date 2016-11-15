#include "stdafx.h"
#include "GamePlayLevel2.h"


GamePlayLevel2::GamePlayLevel2()
{
	gId = States::STATE_LEVEL_2;
	hero = new Player("Game Hero", "Hero.png", 325, 540, 50, 50);
	btnBack = new Button("Button Back", "BackBtn.bmp", 715, 560, 50, 25);
	enemy = new Enemy("Lvl1 Enemy", "Enemy1.png", 295, 0, 88, 105);
	project = new Projectile("Projectile", "Magic.png", hero->getX(), hero->getY(), 15, 14);
	swordImage = new Button("sword", "sword.png", 50, 250, 20, 20);
	sword = new Item("Sword", "..a sharp sword", new std::string[2]{ "sword","sword" });
	keyImage = new Button("Key", "key.png", 693, 160, 25, 25);

}


GamePlayLevel2::~GamePlayLevel2()
{
}

void GamePlayLevel2::Update()
{
	if (project->getFiredStatus() == true)
	{
		project->setX(hero->getX());
		project->setY(hero->getY());
		while (project->getY() >= 20)
		{
			project->setY(project->getY() - 1);
			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			if (project->getY() == 20)
			{
				project->setFiredStatus(false);
			}
		}
	}
}

void GamePlayLevel2::Display(SDL_Surface* aSurface)
{
	// Display the background
	SDL_Surface* background = NULL;
	background = SDL_LoadBMP("Resources/Level2.bmp");
	SDL_BlitSurface(background, NULL, aSurface, NULL);
	SDL_FreeSurface(background);

	if (enemy->getAlive())
	{
		enemy->Display(aSurface);
	}
	if (gFunctions->check_collision(swordImage->getRectangle(), hero->getRectangle()))
	{
		hero->inv->Put(sword);
		swordImage->setX(740);
		swordImage->setY(160);
		std::cout << "You picked up a " + sword->Name() << std::endl;
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
			hero->fScore->setScore(10);
			hero->fExperience->setExperience(250);
			std::cout << "You have slain the beast" << std::endl;
			std::cout << "You gained 10 points" << std::endl;
			std::cout << "You gained 250 XP" << std::endl;
			std::cout << "Your new score is" + std::to_string(hero->fScore->getScore()) << std::endl;
			std::cout << "Your current XP is " + std::to_string(hero->fExperience->getExperience() )<< std::endl;
			std::cout << "You need " + std::to_string(1000 - hero->fExperience->getExperience());
			std::cout << "XP to level up" << std::endl;
			std::cout << "Do you want to progress Y / N" << std::endl;
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
		else if (hero->fHealth->getHealth() <= 0)
		{
			hero->setAlive(false);
		}

		if (hero->fHealth->getHealth() > 0)
		{
			std::cout << "You have " + std::to_string(hero->fHealth->getHealth()) + " lives remaining" << std::endl;
		}
		if (hero->fHealth->getHealth() == 0 && hero->getAlive() == false)
		{
			std::cout << "You have died" << std::endl;
		}
	}
	enemy->ChasePlayer(enemy, hero);
	btnBack->Display(aSurface);
	swordImage->Display(aSurface);
	keyImage->Display(aSurface);
}

States GamePlayLevel2::HandleEvent()
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
				if (hero->getY() >= 20)
				{
					int dy = hero->getY() - 20;
					hero->setY(dy--);
				}
			}
			if (gFunctions->buttonDown(aEvent, SDLK_DOWN))
			{
				if (hero->getY() <= 580 - hero->getH())
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
				if (hero->getX() <= 555 + hero->getW())
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
