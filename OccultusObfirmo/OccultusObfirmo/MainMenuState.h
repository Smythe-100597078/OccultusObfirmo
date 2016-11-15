#pragma once
#include "State.h"
#include "Button.h"

class MainMenuState :
	public State
{
public:
	MainMenuState();
	~MainMenuState();

	void Display(SDL_Surface* aSurface) override;
	States HandleEvent() override;
private:
	Button* btnPlay;
	Button* btnInstruct;
	Button* btnCreate;
	Button* btnExit;
};

