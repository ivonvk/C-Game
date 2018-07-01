#pragma once
class PlayerBullet
{
public:
	PlayerBullet();
	~PlayerBullet();
public:
	int Dmg = 1;
	float life = 20;
	float x, y;
	float x_Speed = 0;
	float y_Speed = 0;
	bool isActive = false;
	bool isShooted = false;
	void BulletUpdate();
	void BulletDraw();
	void BulletReset();
	
};

