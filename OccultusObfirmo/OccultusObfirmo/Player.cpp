#include "stdafx.h"
#include "Player.h"


Player::Player(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH) : Object(aName, aImgName, aX, aY, aW, aH)
{
}

void Player::Display(SDL_Surface* aSurface)
{
	SDL_BlitScaled(gImage, NULL, aSurface, gImageArea);
}

Player::~Player()
{
}

