#include "stdafx.h"
#include "Functions.h"


Functions::Functions()
{
}


Functions::~Functions()
{
}

bool Functions::isOver(int& x, int& y, SDL_Rect& aArea)
{
	bool result = false;

	if ((x > aArea.x) && (x < aArea.x + aArea.w) && (y > aArea.y) && (y < aArea.y + aArea.h))
	{
		result = true;
	}

	return result;
}

bool Functions::leftMouseButtonClicked(SDL_Event* aEvent)
{
	bool result = false;

	if (aEvent->type == SDL_MOUSEBUTTONDOWN && aEvent->button.button == SDL_BUTTON_LEFT)
	{
		result = true;
	}

	return result;
}