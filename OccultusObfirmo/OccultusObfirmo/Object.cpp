#include "stdafx.h"
#include "Object.h"


Object::Object(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH)
{
	std::string imagePath = "Resources/" + aImgName;

	gImage = new SDL_Surface();
	gImageArea = new SDL_Rect();

	gImage = IMG_Load(imagePath.c_str());
	gImageArea->x = aX;
	gImageArea->y = aY;
	gImageArea->w = aW;
	gImageArea->h = aH;
}


Object::~Object()
{
}

SDL_Rect Object::getRectangle()
{
	return *gImageArea;
}

int Object::getX()
{
	return gImageArea->x;
}

int Object::getY()
{
	return gImageArea->y;
}

int Object::getW()
{
	return gImageArea->w;
}

int Object::getH()
{
	return gImageArea->h;
}

void Object::setX(int aLocation)
{
	gImageArea->x = aLocation;
}

void Object::setY(int aLocation)
{
	gImageArea->y = aLocation;
}

void Object::setW(int aSize)
{
	gImageArea->w = aSize;
}

void Object::setH(int aSize)
{
	gImageArea->h = aSize;
}