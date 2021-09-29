#pragma once
class PlayerBullet
{
public:
	PlayerBullet();
	~PlayerBullet();
public:
	int Dmg = 10;
	float life = 20;
	float x, y;
	float x_Speed =0;
		float y_Speed = 0;

	bool isActive = false;

	bool isFired = false;
	void BulletUpdate();
	void BulletDraw();
	void BulletReset();
	float fireSound = 5;
	void FireSoundFunc();
};

