#pragma once
class State
{
public:
	State();
	State(States aId);
	~State();

	virtual void Display(SDL_Surface* aSurface) = 0;
	virtual States HandleEvent(SDL_Event* aEvent) = 0;

	States getID();
private:

protected:
	Functions* gFunctions;
	States gId;
};

