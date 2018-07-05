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
};

