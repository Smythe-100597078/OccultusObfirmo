#include "stdafx.h"
#include "GameEngine.h"
#include <windows.h> 

int main(int argc, char *argv[])
{
	system("color 07");
	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, 267, 209, 300, 638, SWP_NOZORDER);
	GameEngine* myGame = new GameEngine();
	myGame->setup();
	myGame->run();

	return 0;
}