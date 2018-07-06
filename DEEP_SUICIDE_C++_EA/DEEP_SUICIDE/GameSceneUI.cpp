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

void GameSceneUI::MID_SCENE_UI_DRAW() {

	//TOP DOOR

	//TOP DOOR HP BAR BACKGROUND
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(300, 670, 0.3);
	glVertex3f(300, 650, 0.3);
	glVertex3f(500, 650, 0.3);
	glVertex3f(500, 670, 0.3);
	glEnd();
	//TOP DOOR CURRENT HP BAR 
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(300, 670, 0.4);
	glVertex3f(300, 650, 0.4);
	glVertex3f(300+ Draw_iTopDoorHP, 650, 0.4);
	glVertex3f(300+ Draw_iTopDoorHP, 670, 0.4);
	glEnd();

	glColor3f(1, 1, 1);
	glRasterPos3f(375, 680, 0.9);
	string topDoor = to_string(Draw_iTopDoorHP);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)topDoor.c_str());



	//BOTTOM DOOR

	//BOTTOM DOOR HP BAR BACKGROUND
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(300, 245, 0.3);
	glVertex3f(300, 225, 0.3);
	glVertex3f(500, 225, 0.3);
	glVertex3f(500, 245, 0.3);
	glEnd();
	//BOTTOM DOOR CURRENT HP BAR 
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(300, 245, 0.4);
	glVertex3f(300, 225, 0.4);
	glVertex3f(300 + Draw_iBottomDoorHP, 225, 0.4);
	glVertex3f(300 + Draw_iBottomDoorHP, 245, 0.4);
	glEnd();

	glColor3f(1, 1, 1);
	glRasterPos3f(375, 200, 0.9);
	string bottomDoor = to_string(Draw_iBottomDoorHP);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)bottomDoor.c_str());

	//LEFT DOOR

	//LEFT DOOR HP BAR BACKGROUND
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(170, 550, 0.3);
	glVertex3f(170, 350, 0.3);
	glVertex3f(190, 350, 0.3);
	glVertex3f(190, 550, 0.3);
	glEnd();
	//LEFT DOOR CURRENT HP BAR 

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(170, 550, 0.4);
	glVertex3f(170, 550- Draw_iLeftDoorHP, 0.4);
	glVertex3f(190, 550- Draw_iLeftDoorHP, 0.4);
	glVertex3f(190, 550, 0.4);
	glEnd();

	glColor3f(1, 1, 1);
	glRasterPos3f(135, 450, 0.9);
	string leftDoor = to_string(Draw_iLeftDoorHP);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)leftDoor.c_str());

	//RIGHT DOOR

	//RIGHT DOOR HP BAR BACKGROUND
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(600, 550, 0.3);
	glVertex3f(600, 350, 0.3);
	glVertex3f(620, 350, 0.3);
	glVertex3f(620, 550, 0.3);
	glEnd();
	//RIGHT DOOR CURRENT HP BAR 

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(600, 550, 0.4);
	glVertex3f(600, 550 - Draw_iRightDoorHP, 0.4);
	glVertex3f(620, 550 - Draw_iRightDoorHP, 0.4);
	glVertex3f(620, 550, 0.4);
	glEnd();
	glColor3f(1, 1, 1);
	glRasterPos3f(625, 450, 0.9);
	string rightDoor = to_string(Draw_iRightDoorHP);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)rightDoor.c_str());
}





void GameSceneUI::TOP_UI_UPDATE(float HP, int Waves,int Ammo, int MaxAmmo, int Reloading) {
	//UPDATING DRAW NEEDED VALUES
	Draw_iPlayerHP -= HP;
	Draw_iWaves = Waves;
	Draw_iAmmo = Ammo;
	Draw_iMaxAmmo = MaxAmmo;
	Draw_iReloading = Reloading;
}

void GameSceneUI::MID_UI_UPDATE(int topDoorHP, int bottomDoorHP, int leftDoorHP, int rightDoorHP) {

	Draw_iTopDoorHP = topDoorHP;
	Draw_iBottomDoorHP = bottomDoorHP;
	Draw_iLeftDoorHP = leftDoorHP;
	Draw_iRightDoorHP = rightDoorHP;
}

