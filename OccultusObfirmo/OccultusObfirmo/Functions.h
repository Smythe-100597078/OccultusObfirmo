#pragma once
class Functions
{
public:
	Functions();
	~Functions();

	bool Functions::isOver(const SDL_Rect& aArea);
	bool leftMouseButtonClicked(SDL_Event* aEvent);
	bool buttonDown(SDL_Event* aEvent, SDL_Keycode aCode);

};
