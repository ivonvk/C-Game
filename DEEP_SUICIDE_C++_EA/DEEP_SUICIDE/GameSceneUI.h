#pragma once
#include <iostream>
#include <string>
class GameSceneUI
{
public:
	GameSceneUI();
	~GameSceneUI();
public: 
	void TOP_UI_DRAW();
	void MID_SCENE_UI_DRAW();
	void MID_UI_UPDATE(int topDoorHP,int bottomDoorHP,int leftDoorHP,int rightDoorHP);
	void TOP_UI_UPDATE(float HP, int Waves,int Ammo,int MaxAmmo,int Reloading);

	int Draw_iPlayerHP = 100;
	int Draw_iWaves = 1;
	int Draw_iAmmo = 10;
	int Draw_iMaxAmmo = 10;
	int Draw_iReloading = 50;

	int Draw_iTopDoorHP = 200;
	int Draw_iBottomDoorHP = 200;
	int Draw_iLeftDoorHP = 200;
	int Draw_iRightDoorHP = 200;
};

