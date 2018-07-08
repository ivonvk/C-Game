#include "Fence.h"
#include "Item_Pickup.h"
#include "CustomImage.h"
#include <string>
#include "GameSceneUI.h"

using namespace std;

GameSceneUI GSUI;


Fence::Fence()
{
}


Fence::~Fence()
{
}

void Fence::FenceInit() {
	glEnable(GL_TEXTURE_2D);

	string FenceStr = "images/FENCE_1.bmp";
	CustomImage FenceTex(FenceStr.c_str());
	TexID[1] = FenceTex.GenTexture();
}

void Fence::DrawFenceY() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TexID[1]);

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 0.1);
	glTexCoord2f(0, 0); glVertex3f(0, 94, 0.1);
	glTexCoord2f(0, 1); glVertex3f(35, 94, 0.1);
	glTexCoord2f(1, 1); glVertex3f(35, 0, 0.1);
	glEnd();
}

void Fence::DrawFenceX() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TexID[1]);

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0.1);
	glTexCoord2f(0, 1); glVertex3f(0, 35, 0.1);
	glTexCoord2f(1, 1); glVertex3f(70, 35, 0.1);
	glTexCoord2f(1, 0); glVertex3f(70, 0, 0.1);
	glEnd();
}
