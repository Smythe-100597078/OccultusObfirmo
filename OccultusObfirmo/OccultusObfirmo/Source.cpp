#include "stdafx.h"
#include "GameEngine.h"
#include <windows.h> 

int main(int argc, char *argv[])
{
	system("color 0C");
	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, 50, 50, 400, 640, SWP_NOZORDER);
	GameEngine* myGame = new GameEngine();
	myGame->setup();
	myGame->run();
	return 0;
}