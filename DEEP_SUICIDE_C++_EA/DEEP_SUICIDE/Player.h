#pragma once
#include "Enemy.h"
class Player
{
public:
	Player();
	~Player();
public:
	float x;//PLAYER X LOCATION
	float y ;//PLAYER Y LOCATION
	int facing ;//PLAYER FACING DIRCTION
	int HP = 100;//PLAYER CURRENT HP
	int Ammo = 10;//PLAYER CURRENT AMMO
	int MaxAmmo = 10;//PLAYER TOTAL AMMO COULD BE USED
	float Reloading = 0;//PLAYER RELOAD AMMO TIMER
public:
	void PlayerDraw();//DRAW PLAYER ANIMATION
	void PlayerMoving();//PLAYER MOVING CONTROLLER
	


};

