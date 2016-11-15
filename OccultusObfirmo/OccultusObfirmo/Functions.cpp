#include "stdafx.h"
#include "Functions.h"



Functions::Functions()
{
}


Functions::~Functions()
{
}

bool Functions::isOver(const SDL_Rect& aArea)
{
	int x, y;
	bool result = false;

	SDL_GetMouseState(&x, &y);

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


bool Functions::buttonDown(SDL_Event* aEvent, SDL_Keycode aCode)
{
	bool result = false;

	if (aEvent->type == SDL_KEYDOWN && aEvent->key.keysym.sym == aCode)
	{
		
		result = true;
	}
	else if (aEvent->type == SDL_KEYUP && aEvent->key.keysym.sym == aCode)
	{
		
		result = false;
	}

	return result;
}

bool Functions::check_collision(SDL_Rect A, SDL_Rect B)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	//Calculate the sides of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

