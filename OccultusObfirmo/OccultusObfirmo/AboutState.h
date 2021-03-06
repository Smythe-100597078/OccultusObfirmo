#pragma once
#include "State.h"
#include "Button.h"

class AboutState :
	public State
{
public:
	AboutState();
	~AboutState();

	void Display(SDL_Surface* aSurface) override;
	States HandleEvent() override;
private:
	Button* btnBack;
};