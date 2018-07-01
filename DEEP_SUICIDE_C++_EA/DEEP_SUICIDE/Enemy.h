#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
public:
	bool isActive = false;
	int HP = 10;
	float x, y;
	float x_Speed = 0;
	float y_Speed = 0;
	int Dmg = 0;
	void EnemyUpdate();
	void EnemyDraw();
	void EnemyReset();
};

