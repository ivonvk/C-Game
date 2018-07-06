#include "Player.h"
#include "PlayerBullet.h"
#include "GameSceneUI.h"
#include "GL/freeglut.h"

#define VK_W 87
#define VK_S 83
#define VK_A 65
#define VK_D 68
#include <iostream>
using namespace std;

Player::Player()
{
}


Player::~Player()
{
}
void Player::PlayerDraw() {

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(0, 0, 0.5);
	glVertex3f(0,35, 0.5);
	glVertex3f(35, 35, 0.5);
	glVertex3f(35, 0 , 0.5);
	glEnd();
}

void Player::PlayerMoving() {
	if (GetKeyState(VK_W) & 0x8000) {
		facing = 0;
		if (y < 700) {
			y += 5;
		}
		
	}
	if (GetKeyState(VK_S) & 0x8000) {
		facing = 1;
		if (y > 30) {
			y -= 5;
		}
	
	}
	if (GetKeyState(VK_A) & 0x8000) {
		facing = 2;
		if (x >30) {
			x -= 5;
		}
		
	}
	if (GetKeyState(VK_D) & 0x8000) {
		facing = 3;
		if (x <750) {
			x += 5;
		}
	}
	
}
