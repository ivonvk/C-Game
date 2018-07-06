#include "Enemy.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "GL/freeglut.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
void Enemy::EnemyDraw() {

	glBegin(GL_POLYGON);
	glColor3f(color, 0, 0);
	glVertex3f(0, 0, 0.2);
	glVertex3f(0, 35, 0.2);
	glVertex3f(35, 35, 0.2);
	glVertex3f(35, 0, 0.2);
	glEnd();
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
		x += (x - player_x+xmore)*3*-0.005 + bouncing;

		y += (y - player_y+ ymore)*3*-0.005 + bouncing;
	//ENEMY ATTACK SPEED
	if (atkSpeed > 0) {
		atkSpeed -= 1;
	}
	
}
