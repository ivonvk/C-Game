#include "GL/freeglut.h"
#pragma once

class Enemy
{
public:
	Enemy();
	~Enemy();
public:
	float color = (rand() % 255 + 1)*0.01;
	bool isActive = false;
	int HP = 1;
	int x, y;
	float x_Speed = 0;
	float y_Speed = 0;
	int Dmg = 2;
	float atkSpeed = 5.0f;

	GLuint TexID[17];
	float counter = 100;
	int numImg = 0;

	int iEnemyType = 0;
	int xmore = 5;
	int ymore = 5;
	int bouncing = 0;
	int Randspeed = rand() % 3 + 2;
	int speed = 1;

public :
	void EnemyUpdate(int player_x, int player_y);
	void EnemyDraw();
	void EnemyReset();
	float soundCounter;
	void playSound();
	void EnemyCounter();
	void EnemyInit();
};

