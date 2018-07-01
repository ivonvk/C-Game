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
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 35, 0);
	glVertex3f(35, 35, 0);
	glVertex3f(35, 0, 0);
	glEnd();
}
void Enemy::EnemyReset() {
	isActive = false;
	x = 0;
	y = 0;
	x_Speed = 0;
	y_Speed = 0;
}
void Enemy::EnemyUpdate() {
	x += x_Speed;
	y += y_Speed;
}