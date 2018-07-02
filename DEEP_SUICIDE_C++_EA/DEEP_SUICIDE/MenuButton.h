#pragma once
#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
class MenuButton

{
public:
	MenuButton();
	~MenuButton();
public:
	bool staCor = true;
	bool diffCor = false;
	bool quiCor = false;
	bool isActive = true;
	int btnNumMenu = 0;
	int diffNum = 0;
	float btnTimer = 0;
	
	void StartButton();
	void DifficultButton();
	void QuitButton();
	void TitleOper();


};

