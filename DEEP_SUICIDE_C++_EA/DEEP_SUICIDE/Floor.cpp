#include "Floor.h"
#include "CustomImage.h"
#include <string>
#include <iostream>

using namespace std;

Floor::Floor()
{
}


Floor::~Floor()
{
}

void Floor::FloorInit() {
	glEnable(GL_TEXTURE_2D);

	numImg = 1;
	string str = "images/MAPP_1.bmp";
	CustomImage tex(str.c_str());
	//PngImage tex(str.c_str());
	TexID[numImg] = tex.GenTexture();
}

void Floor::DrawFloorX() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TexID[numImg]);
	glTranslatef(0, 0, -0.1);

	for (int x = 0; x < 800; x += 50) {
		glPushMatrix();
		glTranslatef(x, 0, 0);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
		glTexCoord2f(0, 1); glVertex3f(0, 50, 0);
		glTexCoord2f(1, 1); glVertex3f(50, 50, 0);
		glTexCoord2f(1, 0); glVertex3f(50, 0, 0.);
		glEnd();
		glPopMatrix();
	}
}

void Floor::FloorUpdata() {
	counter -= 25;
	if (counter < 0) {
		numImg++;
		numImg = numImg % 8;
		counter = 100;
	}
}
