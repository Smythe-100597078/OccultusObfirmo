#pragma once
#include "State.h"
#include "Button.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

class GamePlayLevel2 :
	public State
{
public:
	GamePlayLevel2();
	~GamePlayLevel2();
	int dy = 0;
	void Display(SDL_Surface* aSurface) override;
	States HandleEvent() override;
	void Update() override;
private:
	Button* btnBack;
	Player* hero;
	Enemy* enemy;
	Projectile* project;
	Button* swordImage;
	Item* sword;
	Button* keyImage;

};