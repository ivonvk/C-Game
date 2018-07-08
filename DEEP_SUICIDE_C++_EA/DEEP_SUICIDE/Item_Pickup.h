#include "GL/freeglut.h"
#include <string>

#pragma once
class Item_Pickup
{
public:
	Item_Pickup();
	~Item_Pickup();
public:
	void ItemDraw();//ITEM DRAWING
	int x;//ITEM X LOCATION
	int y;//ITEM Y LOCATION
	int iType;//ITEM TYPE
	bool isActive = false;//ITEM IS ACTIVE OR NOT


	GLuint TexID[3];
	float counter = 100;
	int numImg = 0;
	void ItemInit();

	
	
};

