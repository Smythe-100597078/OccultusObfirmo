#pragma once
#include "Object.h"

class Button : public Object
{
public:
	
	Button(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH);

	
	~Button();
	void Display(SDL_Surface* aSurface);
private:
};

