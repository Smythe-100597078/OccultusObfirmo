#pragma once
#include "Object.h"

class Player : public Object
{
public:

	Player(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH);
	~Player();
	void Display(SDL_Surface* aSurface);
	void HandleInput( );
	Functions* gFunctions;

private:
};

