#include "GameSceneUI.h"
#include <iostream>
#include <string>
#include "GL/freeglut.h"

using namespace std;

GameSceneUI::GameSceneUI()
{
}


GameSceneUI::~GameSceneUI()
{
}
void GameSceneUI::TOPUIDRAW() {
	glColor3f(0.5, 1, 0.5);
	glRasterPos3f(20, 450, 0.4);
	string PlayerHP = "PlayerHP:"+ to_string(iPlayerHP);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)PlayerHP.c_str());

	glColor3f(1, 0, 0);
	glRasterPos3f(290, 450, 0.4);
	string Wave = "Wave:";
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)Wave.c_str());




	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.3, 0.3);
	glVertex3f(0, 480, 0.2);
	glVertex3f(0, 430, 0.2);
	glVertex3f(640, 430, 0.2);
	glVertex3f(640, 480, 0.2);
	glEnd();
}
void GameSceneUI::TOPUIUPDATE() {
	
}