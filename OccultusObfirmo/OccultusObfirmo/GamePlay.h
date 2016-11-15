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
	int dy = 0;
	void Display(SDL_Surface* aSurface) override;
	States HandleEvent() override;
private:
	Button* btnBack;
	Player* hero;
}; 