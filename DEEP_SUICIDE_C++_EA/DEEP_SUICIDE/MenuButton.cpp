#include "MenuButton.h"
#include "GL/freeglut.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
using namespace std;
#define VK_W 87
#define VK_S 83
#define VK_A 65
#define VK_D 68
#define VK_F 70
MenuButton::MenuButton()
{
}


MenuButton::~MenuButton()
{
}
void MenuButton::StartButton() {
	if (isActive) {
		glPushMatrix();
		glTranslatef(0, -30, 0);
		glBegin(GL_POLYGON);
		if (staCor) {
			glColor3f(0.3, 1, 0.3);
		}
		else {
			glColor3f(1, 0.3, 0.3);
		}
		glVertex3f(0, 200, 0.2);
		glVertex3f(0, 150, 0.2);
		glVertex3f(250, 150, 0.2);
		glVertex3f(250, 200, 0.2);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.2, 0.2, 0.3);
		glVertex3f(10, 195, 0.3);
		glVertex3f(10, 155, 0.3);
		glVertex3f(240, 155, 0.3);
		glVertex3f(240, 195, 0.3);
		glEnd();

		glColor3f(1, 0, 0);
		glRasterPos3f(100, 170, 0.4);
		string strStart = "Start";
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)strStart.c_str());
	}
}
void MenuButton::DifficultButton() {
	if (isActive) {
		glPushMatrix();
		glTranslatef(0, -30, 0);
		glBegin(GL_POLYGON);
		if (diffCor) {
			glColor3f(0.3, 1, 0.3);
		}
		else {
			glColor3f(1, 0.3, 0.3);
		}
		glVertex3f(0, 200, 0.2);
		glVertex3f(0, 150, 0.2);
		glVertex3f(250, 150, 0.2);
		glVertex3f(250, 200, 0.2);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.2, 0.2, 0.3);
		glVertex3f(10, 195, 0.3);
		glVertex3f(10, 155, 0.3);
		glVertex3f(240, 155, 0.3);
		glVertex3f(240, 195, 0.3);
		glEnd();

		glColor3f(1, 0, 0);
		glRasterPos3f(30, 170, 0.4);
		string strDifficult = "";
		switch (diffNum) {
		case 1:
			strDifficult = "Difficult: Easy(3Waves)";
			break;
		case 2:
			strDifficult = "Difficult: Normal(6Waves)";
			break;
		case 3:
			strDifficult = "Difficult: Hard(10Waves)";
			break;
		}
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)strDifficult.c_str());
	}
}
void MenuButton::QuitButton() {
	if (isActive) {
		glPushMatrix();
		glTranslatef(0, -30, 0);
		glBegin(GL_POLYGON);
		if (quiCor) {
			glColor3f(0.3, 1, 0.3);
		}
		else {
			glColor3f(1, 0.3, 0.3);
		}
		glVertex3f(0, 200, 0.2);
		glVertex3f(0, 150, 0.2);
		glVertex3f(250, 150, 0.2);
		glVertex3f(250, 200, 0.2);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.2, 0.2, 0.3);
		glVertex3f(10, 195, 0.3);
		glVertex3f(10, 155, 0.3);
		glVertex3f(240, 155, 0.3);
		glVertex3f(240, 195, 0.3);
		glEnd();

		glColor3f(1, 0, 0);
		glRasterPos3f(100, 170, 0.4);
		string strQuit = "Quit";
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)strQuit.c_str());
	}
}
void MenuButton::TitleOper() {
	if (btnTimer <= 0) {
		if (GetKeyState(VK_S) & 0x8000) {
			if (btnNumMenu + 1 < 3) {
				btnNumMenu += 1;
				btnTimer = 5;
			}
		}
		if (GetKeyState(VK_W) & 0x8000) {
			if (btnNumMenu - 1 >= 0) {
				btnNumMenu -= 1;
				btnTimer = 5;
			}
		}
		
	}
	else {
		btnTimer -= 1;
	}
	



	switch (btnNumMenu) {
	case 0:
		staCor = true;
		diffCor = false;
		quiCor = false;
		break;
	case 1:
		staCor = false;
		diffCor = true;
		quiCor = false;
		break;
	case 2:
		staCor = false;
		diffCor = false;
		quiCor = true;
		break;
	}
}