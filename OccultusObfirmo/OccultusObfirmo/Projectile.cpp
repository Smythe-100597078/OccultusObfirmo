#include "stdafx.h"
#include "Projectile.h"


Projectile::Projectile(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH) : Object(aName, aImgName, aX, aY, aW, aH)
{
}

void Projectile::Display(SDL_Surface* aSurface)
{
	SDL_BlitScaled(gImage, NULL, aSurface, gImageArea);
}

Projectile::~Projectile()
{
}