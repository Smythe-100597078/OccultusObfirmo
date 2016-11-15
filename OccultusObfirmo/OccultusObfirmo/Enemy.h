#pragma once
#include "Object.h"
#include "Enemy.h"
#include "Player.h"

class Enemy : public Object
{
public:

	Enemy(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH);
	~Enemy();
	void Display(SDL_Surface* aSurface);

	Functions* gFunctions;
	void ChasePlayer(Enemy* enemy, Player* p);
	void Move(Enemy* c, double distanceX, double distanceY);
	bool collided = false;
	bool getCollided()
	{
		return collided;
	}
	void setCollided(bool a)
	{
		collided = a;
	}
	bool getAlive()
	{
		return alive;
	}
	void setAlive(bool dead)
	{
		alive = dead;
	}

	Health* fHealth = new Health(10);
private:

protected:
	bool alive = true;

};