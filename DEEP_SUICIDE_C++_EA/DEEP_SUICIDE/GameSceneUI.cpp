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
void GameSceneUI::TOP_UI_DRAW() {
	//TOP UI BOX DRAW
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.3, 0.3);
	glVertex3f(0, 800, 0.2);
	glVertex3f(0, 750, 0.2);
	glVertex3f(800, 750, 0.2);
	glVertex3f(800, 800, 0.2);
	glEnd();

	//HP BAR BACKGROUND COLOR RED
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(10, 790, 0.3);
	glVertex3f(10, 755, 0.3);
	glVertex3f(200, 755, 0.3);
	glVertex3f(200, 790, 0.3);
	glEnd();

	//HP BAR CUR HP BAR
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(10, 790, 0.4);
	glVertex3f(10, 755, 0.4);
	glVertex3f((Draw_iPlayerHP*0.01)*200, 755, 0.4);
	glVertex3f((Draw_iPlayerHP*0.01)*200, 790, 0.4);
	glEnd();

	//HP BAR TEXT
	glColor3f(0, 0, 1);
	glRasterPos3f(20, 765, 1);
	string PlayerHP = "PlayerHP:"+ to_string(Draw_iPlayerHP);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)PlayerHP.c_str());

	//WAVE DISPLAY
	glColor3f(1, 1, 0);
	glRasterPos3f(375, 765, 1);
	string Wave = "Wave:"+to_string(Draw_iWaves);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)Wave.c_str());

	//AMMO BAR BACKGROUND COLOR RED
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(590, 790, 0.3);
	glVertex3f(590, 755, 0.3);
	glVertex3f(790, 755, 0.3);
	glVertex3f(790, 790, 0.3);
	glEnd();

	//AMMO BAR CUR AMMO BAR
	if (Draw_iReloading <= 0) {
		glBegin(GL_POLYGON);
		glColor3f(0, 1, 0);
		glVertex3f(590, 790, 0.4);
		glVertex3f(590, 755, 0.4);
		glVertex3f(((Draw_iAmmo * 200 * 0.1)) + 590, 755, 0.4);
		glVertex3f(((Draw_iAmmo * 200 * 0.1)) + 590, 790, 0.4);
		glEnd();
		//AMMO BAR TEXT IF RELOADED
		glColor3f(0, 0, 1);
		glRasterPos3f(595, 765, 1);
		string Ammo = "Ammo:" + to_string(Draw_iAmmo) + "/" + to_string(Draw_iMaxAmmo);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)Ammo.c_str());
	}
	else {
		glBegin(GL_POLYGON);
		glColor3f(0.2, 0.2, 0.2);
		glVertex3f(590, 790, 0.4);
		glVertex3f(590, 755, 0.4);
		glVertex3f(((Draw_iReloading * 50*0.1)) + 590, 755, 0.4);
		glVertex3f(((Draw_iReloading * 50 * 0.1)) + 590, 790, 0.4);
		glEnd();

		//AMMO BAR TEXT IF RELOADING
		glColor3f(1, 1, 1);
		glRasterPos3f(595, 765, 1);
		string Ammo = "RELOADING";
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)Ammo.c_str());
	}

	

}
void GameSceneUI::TOP_UI_UPDATE(float HP, int Waves,int Ammo, int MaxAmmo, int Reloading) {
	//UPDATING DRAW NEEDED VALUES
	Draw_iPlayerHP -= HP;
	Draw_iWaves = Waves;
	Draw_iAmmo = Ammo;
	Draw_iMaxAmmo = MaxAmmo;
	Draw_iReloading = Reloading;
}

