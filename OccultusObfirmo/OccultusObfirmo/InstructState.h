#pragma once
#include "State.h"
#include "Button.h"

class InstructState :
	public State
{
public:
	InstructState();
	~InstructState();

	void Display(SDL_Surface* aSurface) override;
	States HandleEvent() override;
private:
	Button* btnBack;
};