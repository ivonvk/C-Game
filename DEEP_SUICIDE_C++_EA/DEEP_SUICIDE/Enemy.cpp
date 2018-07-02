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
	glTranslatef(x,y, 0);
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
void Enemy::EnemyUpdate(int player_x, int player_y) {
	


		x += (x - player_x)*1.5*-0.015;

		y += (y - player_y)*1.5*-0.015;

	if (atkSpeed > 0) {
		atkSpeed -= 1;
	}
	
}
