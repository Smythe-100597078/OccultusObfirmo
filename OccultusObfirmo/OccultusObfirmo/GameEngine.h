#pragma once
#pragma once
#include "StateManager.h"
#include "Button.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void init();
	void setup();
	void close();

	void handleEvent();
	void update();
	void display();

	bool isExiting();
private:
	bool exiting;

	Functions* gFunctions;
	StateManager* gStateManager;

	//The window we'll be rendering to
	SDL_Window* gWindow;

	//The surface contained by the window
	SDL_Surface* gScreenSurface;

};

