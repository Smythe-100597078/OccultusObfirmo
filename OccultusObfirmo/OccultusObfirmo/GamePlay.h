#pragma once
#include "State.h"
#include "Button.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

class GamePlay :
	public State
{
public:
	GamePlay();
	~GamePlay();
	int dy = 0;
	void Display(SDL_Surface* aSurface) override;
	States HandleEvent() override;
private:
	Button* btnBack;
	Player* hero;
	Enemy* enemy;
	Projectile* project;
	Button* keyImage;
	Item* key;

}; 