#pragma once
#include "GL/freeglut.h"
class Enemy
{
public:
	Enemy();
	~Enemy();
public:
	float color = (rand() % 255 + 1)*0.01;
	bool isActive = false;
	int HP = 10;
	int x, y;
	float x_Speed = 0;
	float y_Speed = 0;
	int Dmg = 2;
	float atkSpeed = 5.0f;
	void EnemyUpdate(int player_x, int player_y);
	void EnemyDraw();
	void EnemyReset();

};

