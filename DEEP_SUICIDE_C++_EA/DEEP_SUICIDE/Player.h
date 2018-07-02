#pragma once
#include "Enemy.h"
class Player
{
public:
	Player();
	~Player();
public:
	float x = 0;
	float y = 0;
	
	int facing ;
	Enemy enemy;
	int HP = 100;
public:
	void PlayerDraw();
	void PlayerController();
	


};

