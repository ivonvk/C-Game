#include "Item_Pickup.h"
#include "CustomImage.h"
#include <string>

using namespace std;


Item_Pickup::Item_Pickup()
{
}


Item_Pickup::~Item_Pickup()
{
}

void Item_Pickup::ItemInit() {
	glEnable(GL_TEXTURE_2D);

	string str1 = "images/Item_1.bmp";
	string str2 = "images/Item_2.bmp";
	string str3 = "images/Item_3.bmp";


	CustomImage tex1(str1.c_str());
	CustomImage tex2(str2.c_str());
	CustomImage tex3(str3.c_str());

	TexID[1] = tex1.GenTexture();
	TexID[2] = tex2.GenTexture();
	TexID[3] = tex3.GenTexture();
}

void Item_Pickup::ItemDraw() {
	//DETECT ITEM TYPE AND GIVE COLOR
	glEnable(GL_TEXTURE_2D);

	switch (iType) {
	case 0:
		glBindTexture(GL_TEXTURE_2D, TexID[1]);
		glPushMatrix();
		glScalef(2, 2, 0);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		break;
	case 1:
		glBindTexture(GL_TEXTURE_2D, TexID[2]);
		glPushMatrix();
		glScalef(2, 2, 0);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		break;
	case 2:
		glBindTexture(GL_TEXTURE_2D, TexID[3]);
		glPushMatrix();
		glScalef(2, 2, 0);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		break;
	}
	//DRAW ITEM
	glTexCoord2f(0, 0); glVertex3f(0, 0, 1);
	glTexCoord2f(0, 1); glVertex3f(0, 15, 1);
	glTexCoord2f(1, 1); glVertex3f(15, 15, 1);
	glTexCoord2f(1, 0); glVertex3f(15, 0, 1);
	glEnd();
	glPopMatrix();
}
