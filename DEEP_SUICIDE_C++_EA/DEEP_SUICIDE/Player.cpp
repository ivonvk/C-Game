#include "Player.h"
#include "PlayerBullet.h"
#include "GameSceneUI.h"
#include "CustomImage.h"
#include <string>
#include <iostream>

#define VK_W 87
#define VK_S 83
#define VK_A 65
#define VK_D 68

using namespace std;

Player::Player()
{
}


Player::~Player()
{
}
void Player::PlayerUpdata() {
	counter -= 25;
	if (counter < 0) {
		numImg++;
		numImg = numImg % 8;
		counter = 100;
	}
}

void Player::PlayerInit() {
	glEnable(GL_TEXTURE_2D);

	for (int i = 0; i < 20; i++) {
		numImg = i;
		string str = "images/SMR_" + to_string(i) + ".bmp";
		CustomImage tex(str.c_str());
		//PngImage tex(str.c_str());
		TexID[numImg] = tex.GenTexture();
	}
}

void Player::PlayerDraw() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TexID[numImg]);

	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(0.2, 0.2, 0.2);

	if (!isRight & !isLeft & !isDown & !isUp) {
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 0);
		glVertex3f(0.0f, 0.0f, 0.0);
		glTexCoord2f(0, 1);
		glVertex3f(0.0f, 206.0f, 0);
		glTexCoord2f(1, 1);
		glVertex3f(313.0f, 206.0f, 0);
		glTexCoord2f(1, 0);
		glVertex3f(313.0f, 0.0f, 0);
	}

	if (isRight) {
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 0);
		glVertex3f(0.0f, 0.0f, 0.0);
		glTexCoord2f(0, 1);
		glVertex3f(0.0f, 206.0f, 0);
		glTexCoord2f(1, 1);
		glVertex3f(313.0f, 206.0f, 0);
		glTexCoord2f(1, 0);
		glVertex3f(313.0f, 0.0f, 0);
	}
	else if (isLeft) {
		glBegin(GL_POLYGON);
		glTexCoord2f(1, 0);
		glVertex3f(0.0f, 0.0f, 0.0);
		glTexCoord2f(1, 1);
		glVertex3f(0.0f, 206.0f, 0);
		glTexCoord2f(0, 1);
		glVertex3f(313.0f, 206.0f, 0);
		glTexCoord2f(0, 0);
		glVertex3f(313.0f, 0.0f, 0);
	}
	else if (isUp) {
		glBegin(GL_POLYGON);
		glTexCoord2f(0, 1);
		glVertex3f(0.0f, 0.0f, 0.0);
		glTexCoord2f(1, 1);
		glVertex3f(0.0f, 313.0f, 0);
		glTexCoord2f(1, 0);
		glVertex3f(206.0f, 313.0f, 0);
		glTexCoord2f(0, 0);
		glVertex3f(206.0f, 0.0f, 0);
	}
	else if (isDown) {
		glBegin(GL_POLYGON);
		glTexCoord2f(1, 0);
		glVertex3f(0.0f, 0.0f, 0.0);
		glTexCoord2f(0, 0);
		glVertex3f(0.0f, 313.0f, 0);
		glTexCoord2f(0, 1);
		glVertex3f(206.0f, 313.0f, 0);
		glTexCoord2f(1, 1);
		glVertex3f(206.0f, 0.0f, 0);
	}

	glEnd();
	glPopMatrix();

	
	/*glBegin(GL_POLYGON);
	//glColor3f(1, 1, 1);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0,35, 0.5);
	glVertex3f(35, 35, 0.5);
	glVertex3f(35, 0 , 0.5);
	glEnd();*/
}

void Player::PlayerMoving() {
	if (GetKeyState(VK_W) & 0x8000) {
		facing = 0;
		if (y < 700) {
			y += 5;
			isUp = true;
			isLeft = false;
			isDown = false;
			isRight = false;
		}
		
	}
	if (GetKeyState(VK_S) & 0x8000) {
		facing = 1;
		if (y > 30) {
			y -= 5;
			isUp = false;
			isLeft = false;
			isDown = true;
			isRight = false;
		}
	
	}
	if (GetKeyState(VK_A) & 0x8000) {
		facing = 2;
		if (x >30) {
			x -= 5;
			isUp = false;
			isLeft = true;
			isDown = false;
			isRight = false;
		}
		
	}
	if (GetKeyState(VK_D) & 0x8000) {
		facing = 3;
		if (x <750) {
			x += 5;
			isUp = false;
			isLeft = false;
			isDown = false;
			isRight = true;
		}
	}
	
}
