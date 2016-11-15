#pragma once
#include "State.h"
#include "Button.h"

class GameOverState :
	public State
{
public:
	GameOverState();
	~GameOverState();

	void Display(SDL_Surface* aSurface) override;
	States HandleEvent() override;
private:
	Button* btnBack;
};