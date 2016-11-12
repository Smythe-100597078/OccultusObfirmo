#include "stdafx.h"
#include "GameEngine.h"
#include "Button.h"


GameEngine::GameEngine()
{
	gFunctions = new Functions();
	gStateManager = new StateManager();
	gWindow = NULL;
	gScreenSurface = NULL;
	exiting = false;
}


GameEngine::~GameEngine()
{
}

void GameEngine::display()
{
	// Clear Screen
	SDL_FillRect(gScreenSurface, NULL, 0x000000);
	SDL_Surface* gHelloWorld = NULL;
	gHelloWorld = SDL_LoadBMP("Resources/MainMenu.bmp");
	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
	gStateManager->getCurrentSate()->Display(gScreenSurface);

	// Update window
	SDL_UpdateWindowSurface(gWindow);
}

void GameEngine::handleEvent()
{
	SDL_Event* e = new SDL_Event();

	//Handle events on queue
	while (SDL_PollEvent(e) != 0)
	{
		//User requests quit
		if (e->type == SDL_QUIT)
		{
			exiting = true;
			close();
		}
		else
		{
			States result = gStateManager->getCurrentSate()->HandleEvent(e);
			if (result == States::STATE_EXIT)
			{
				exiting = true;
			}
			else
			{
				gStateManager->setNextState(result);
			}
		}
	}
}

void GameEngine::update()
{
	gStateManager->changeState();
}


void GameEngine::setup()
{
	init();
}

void GameEngine::init()
{

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Error::Display("SDL could not initialized");
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

		if (gWindow == NULL)
		{
			Error::Display("Window could not be created");
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);

			if (IMG_Init(IMG_INIT_PNG) < 0)
			{
				Error::Display("Could not initialize SDL IMG");
			}
		}
	}
}

void GameEngine::close()
{
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL and Image
	IMG_Quit();
	SDL_Quit();
}

bool GameEngine::isExiting()
{
	return exiting;
}