#pragma once
class GameSceneUI
{
public:
	GameSceneUI();
	~GameSceneUI();
public: 
	void TOPUIDRAW();
	void TOPUIUPDATE(float HP, int Waves);
	int iPlayerHP = 100;
	int iWaves = 1;
};

