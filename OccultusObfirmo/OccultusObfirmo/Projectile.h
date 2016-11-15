#pragma once
#include "Object.h"

class Projectile : public Object
{
public:

	Projectile(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH);


	~Projectile();
	void Display(SDL_Surface* aSurface);
	bool getFiredStatus()
	{
		return fired;
	}

	void setFiredStatus(bool status)
	{
		fired = status;
	}
	bool getAlive()
	{
		return alive;
	}
	void setAlive(bool dead)
	{
		alive = dead;
	}
private:

protected: 
	bool fired = false;
	bool alive = true;
};
