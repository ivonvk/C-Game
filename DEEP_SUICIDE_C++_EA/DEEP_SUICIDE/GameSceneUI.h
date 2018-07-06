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
	void TOP_UI_UPDATE(float HP, int Waves,int Ammo,int MaxAmmo,int Reloading);

	int Draw_iPlayerHP = 100;
	int Draw_iWaves = 1;
	int Draw_iAmmo = 10;
	int Draw_iMaxAmmo = 10;
	int Draw_iReloading = 50;
};

