#pragma once
class State
{
public:
	State();
	State(States aId);
	~State();

	virtual void Display(SDL_Surface* aSurface) = 0;
	virtual States HandleEvent() = 0;
	virtual void Update();

	States getID();
private:

protected:
	Functions* gFunctions;
	States gId;
	SDL_Event* aEvent = new SDL_Event();
};

