#pragma once
#include "Object.h"
#include "Health.h"
#include "Score.h"
#include "Experience.h"
#include "Player.h"
#include "Inventory.h"


class Player : public Object
{
public:

	Player(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH);
	~Player();
	void Display(SDL_Surface* aSurface);

	Functions* gFunctions;

	void AddScore(int aScore)
	{
		score += aScore;
	}

	bool getAlive()
	{
		return alive;
	}
	void setAlive(bool dead)
	{
		alive = dead;
	}


	void removelife()
	{
		int x = fHealth->getHealth();
		fHealth->setHealth(x - 1);
	}
	Health* fHealth = new Health(3);
	Score* fScore = new Score(0);
	Experience* fExperience = new Experience(0);
	Inventory* inv = new Inventory();
private:

protected:
	int score = 0;
	bool alive = true;

};