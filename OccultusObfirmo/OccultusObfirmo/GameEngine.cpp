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
	do
	{
		// Clear Screen
		SDL_FillRect(gScreenSurface, NULL, 0x000000);

		gStateManager->getCurrentSate()->Display(gScreenSurface);

		// Update window
		SDL_UpdateWindowSurface(gWindow);
	} while (!exiting);
}

void GameEngine::handleEvent()
{

	States result = STATE_NULL;

	result = gStateManager->getCurrentSate()->HandleEvent();
	gStateManager->setNextState(result);

	if (result == STATE_EXIT)
	{
		exiting = true;
		close();
	}

	if (result != gStateManager->getCurrentSate()->getID() && result != STATE_NULL)
	{
		gStateManager->changeState();
	}
}

void GameEngine::update()
{

	gStateManager->changeState();
}


void GameEngine::setup()
{
	std::cout << "Initializing Engine" << std::endl;
	init();
	gDisplayThread = new std::thread(&GameEngine::display, this);
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
		SDL_SetWindowPosition(gWindow, 444, 82);
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
	gDisplayThread->join();

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

void GameEngine::run()
{
	std::cout << "Starting game loop" << std::endl;
	do
	{
		//display();
		handleEvent();
		update();
	} while (!isExiting());
}