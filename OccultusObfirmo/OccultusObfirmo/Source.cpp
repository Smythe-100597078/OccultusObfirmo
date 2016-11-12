#include "stdafx.h"
#include "GameEngine.h"

int main(int argc, char *argv[])
{
	GameEngine* myGame = new GameEngine();
	myGame->setup();

	while (!myGame->isExiting())
	{
		myGame->display();
		myGame->handleEvent();
		myGame->update();
	}

	return 0;
}