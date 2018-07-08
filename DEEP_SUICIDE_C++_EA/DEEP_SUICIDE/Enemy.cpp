#include "Enemy.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "CustomImage.h"
#include <string>

using namespace std;


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::EnemyInit() {
	glEnable(GL_TEXTURE_2D);

	for (int i = 0; i < 17; i++) {
		numImg = i;
		string str = "images/SM_" + to_string(i) + ".bmp";
		CustomImage tex(str.c_str());
		//PngImage tex(str.c_str());
		TexID[numImg] = tex.GenTexture();
	}
}

void Enemy::EnemyDraw() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TexID[numImg]);

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glScalef(1.2, 1.2, 1.2);
	//glColor3f(color, 0, 0);
	glTexCoord2f(0, 0);  glVertex3f(0, 0, 0.2);
	glTexCoord2f(0, 1); glVertex3f(0, 35, 0.2);
	glTexCoord2f(1, 1); glVertex3f(35, 35, 0.2);
	glTexCoord2f(1, 0); glVertex3f(35, 0, 0.2);
	glEnd();
	glPopMatrix();
}
void Enemy::EnemyReset() {
	isActive = false;
	x = 0;//ENEMY X LOACTION
	y = 0;//ENEMY Y LOACTION
	x_Speed = 0;//ENEMY X MOVING
	y_Speed = 0;//ENEMY Y MOVING
}
void Enemy::EnemyUpdate(int player_x, int player_y) {

	int xmore = 0;
	int ymore = 0;

	int bouncing = 0;
	//ENEMY BOUNCING AND MORE NEARBY THE PLAYER
	if (player_x > 0) {
		xmore = -30;
		bouncing = -rand() % 3 + 1;
	}
	else {
		xmore = 30;
		bouncing = rand() % 3 + 1;
	}
	if (player_y > 0) {
		ymore = -30;
		bouncing = -rand() % 3 + 1;
	}
	else {
		ymore = 30;
		bouncing = rand() % 3 + 1;
	}
	//ENEMY BOUNCING AND MOVING
	x += (x - player_x + xmore) * 3 * -0.005 + bouncing;

	y += (y - player_y + ymore) * 3 * -0.005 + bouncing;
	//ENEMY ATTACK SPEED
	if (atkSpeed > 0) {
		atkSpeed -= 1;
	}
}

void Enemy::EnemyCounter() {
	counter -= 25;
	if (counter < 0) {
		numImg++;
		numImg = numImg % 8;
		counter = 100;
	}
}
