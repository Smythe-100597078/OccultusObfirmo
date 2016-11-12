#pragma once
class Functions
{
public:
	Functions();
	~Functions();

	bool isOver(int& x, int& y, SDL_Rect& aArea);
	bool leftMouseButtonClicked(SDL_Event* aEvent);
};
