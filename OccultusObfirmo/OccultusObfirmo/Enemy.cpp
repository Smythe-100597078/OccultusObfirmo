#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH) : Object(aName, aImgName, aX, aY, aW, aH)
{
}

void Enemy::Display(SDL_Surface* aSurface)
{
	SDL_BlitScaled(gImage, NULL, aSurface, gImageArea);
}

Enemy::~Enemy()
{
}

void Enemy::ChasePlayer(Enemy* enemy, Player* p)
{
	double x;
	double y;
	x = p->getX();
	y = p->getY();
	Move(enemy, x, y);

}

void Enemy::Move(Enemy* c, double distanceX, double distanceY)
{
	double x, y;
	double speed = 1;
	x = c->getX();
	y = c->getY();

		if (distanceX < x)
		{
			c->setX((x -= speed));
		}
		if (distanceX > x)
		{
			c->setX((x += speed));
		}
		if (distanceY < y)
		{
			c->setY((y -= speed));
		}
		if (distanceY > y)
		{
			c->setY((y += speed));
		}
	}
