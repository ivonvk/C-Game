#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
public:
	bool isActive = false;
	int HP = 999;
	int x, y;
	float x_Speed = 0;
	float y_Speed = 0;
	int Dmg = 2;
	float atkSpeed = 5.0f;
	void EnemyUpdate(int player_x, int player_y);
	void EnemyDraw();
	void EnemyReset();

};

