#include "PlayerBullet.h"
#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <mmsystem.h>
#include <iostream>
PlayerBullet::PlayerBullet()
{
}


PlayerBullet::~PlayerBullet()
{

}
void PlayerBullet::BulletUpdate()
{
	
	//BULLET LOCATION MOVING
	x += x_Speed;
	y += y_Speed;
}
void PlayerBullet::BulletDraw(){
	//BULLET  ANIMATION DRAWING
	glBegin(GL_POLYGON);
	glColor3f(255, 255, (rand()%255+1)*0.01f);
	for (int i = 0; i < 360;i += 15) {
		float a = i* M_PI / 180.0f;
		glVertex2f((cos(a)*(5)) + x, (sin(a)*(5 )) + y);
	}
	glEnd();
}

void PlayerBullet::BulletReset() {
	
	isActive = false;
	life = 400;
	
}