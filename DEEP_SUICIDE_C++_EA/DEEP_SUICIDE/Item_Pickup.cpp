#include "Item_Pickup.h"
#include "GL/freeglut.h"


Item_Pickup::Item_Pickup()
{
}


Item_Pickup::~Item_Pickup()
{
}
void Item_Pickup::ItemDraw() {
	//DETECT ITEM TYPE AND GIVE COLOR
	glBegin(GL_POLYGON);
	switch (iType) {
	case 0:
		glColor3f(0, 1, 0);
		break;
	case 1:
		glColor3f(1, 1, 1);
		break;
	case 2:
		glColor3f(1, 1, 0);
		break;
	}
	//DRAW ITEM
	glVertex3f(0, 0, 1);
	glVertex3f(0, 15, 1);
	glVertex3f(15, 15, 1);
	glVertex3f(15, 0, 1);
	glEnd();
}
