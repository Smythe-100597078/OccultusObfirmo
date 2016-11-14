#pragma once
#include "State.h"
#include "Button.h"
#include "Player.h"

class GamePlay :
	public State
{
public:
	GamePlay();
	~GamePlay();

	void Display(SDL_Surface* aSurface) override;
	States HandleEvent(SDL_Event* aEvent) override;
private:
	Button* btnBack;
	Player* hero;
}; 