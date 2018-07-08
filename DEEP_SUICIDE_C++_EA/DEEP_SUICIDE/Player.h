#pragma once
#include "Enemy.h"
#include "GL/freeglut.h"
#include <string>

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
	int MaxAmmo = 100;//PLAYER TOTAL AMMO COULD BE USED
	float Reloading = 0;//PLAYER RELOAD AMMO TIMER

	GLuint TexID[20];
	float counter = 100;
	int numImg = 0;

	int StartGame = 1;

	bool isLeft = false;
	bool isUp = false;
	bool isDown = false;
	bool isRight = false;

public:
	void PlayerDraw();//DRAW PLAYER ANIMATION
	void PlayerMoving();//PLAYER MOVING CONTROLLER
	void PlayerInit();
	void PlayerUpdata();

};

