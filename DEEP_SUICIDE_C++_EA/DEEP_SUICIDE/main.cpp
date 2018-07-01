/*  Filename:       main.cpp
    Description:    MET4335 - Lab05
*/
#include <windows.h>  // include all the windows headers
#include<windowsx.h>
#include "MenuButton.h"
#include "GameSceneUI.h"
#include "GL/freeglut.h"
#include"PlayerBullet.h"
#include"Enemy.h"
#include <iostream>
#include "Player.h"
#include<conio.h>
#include <string>
#include <cstdlib>
#define VK_W 87
#define VK_S 83
#define VK_A 65
#define VK_D 68
#define VK_F 70

using namespace std;
int Scene = 0;

int TotalBullet = 150;
int TotalEnemy = 150;
int timerCount = 0;
float cam_x = 0;
float cam_y = 0;

float player_rot = 0.0f;
float player_y = 0.0f;
float playerY_force = 0.0f;

float player_x = 0.0f;
float playerX_force = 0.0f;
int playerForBac = 0;
int playerLR = 0;

float fireTimer;
Player player;
PlayerBullet PB[150];
MenuButton MB;
GameSceneUI GSUI;
Enemy enemy[150];

void initRendering() {
    glEnable(GL_DEPTH_TEST);                    // test 3D depth
}

void gameStart() {
	enemy[0].isActive = true;
}

void cameraSetup(int w, int h) {
    glViewport(0, 0, 640, 480);
    glMatrixMode(GL_PROJECTION);                // select projection matrix
    glLoadIdentity();                           // reset projection matrix
    //gluPerspective(100.0, 1, 1.0, 100.0);        // set up a perspective projection matrix
	gluOrtho2D(0, 640, 0, 480);
}
void GameSceneDraw() {
	
}
void StartSceneMenu() {
	//Top
	
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.1);
	glVertex3f(0, 0, 0.2);
	glVertex3f(0, 200, 0.2);
	glVertex3f(320, 0, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.0, 0.0);
	glVertex3f(0, 0, 0.2);
	glVertex3f(0, 250, 0.2);
	glVertex3f(370, 0, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1);
	glVertex3f(0, 480, 0.2);
	glVertex3f(0, 410, 0.2);
	glVertex3f(640, 410, 0.2);
	glVertex3f(640, 480, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2,0.3);
	glVertex3f(10, 470, 0.3);
	glVertex3f(10, 420, 0.3);
	glVertex3f(630, 420, 0.3);
	glVertex3f(630, 470, 0.3);
	glEnd();

	glColor3f(1, 0, 0);
	glRasterPos3f(250, 440,0.4);
	string Title = "SUICIDE DEEPLY";
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)Title.c_str());
	//Top

	//Right
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(640, 0, 0.2);
	glVertex3f(320, 0, 0.2);
	glVertex3f(640, 200, 0.2);
	glEnd();
	glTranslatef(0, -10, 0);

	//GameStartButton
	
		glPushMatrix();
		glTranslatef(205, 200, 0);
		MB.StartButton();

		glTranslatef(0, -40, 0);
		MB.DifficultButton();

		glTranslatef(0, -40, 0);
		MB.QuitButton();

		glPopMatrix();
	



}

void display() {
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear Screen and Depth Buffer
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	//gluLookAt(cam_x, cam_y, 1, cam_x, cam_y, 0, 0, 1, 0);
	if (Scene == 0) {
		StartSceneMenu();

	}
	

	
	if(Scene!=0) {
		
		GSUI.TOPUIDRAW();
		glTranslatef(300, 220, 0);
		glPushMatrix();
	
		glTranslatef(player.x, player.y, 0);
		player.PlayerDraw();
		glPopMatrix();
		
		for (int i = 0;i < TotalBullet;i++) {
			if (PB[i].isActive) {
				PB[i].BulletDraw();
			}
		}
		for (int i = 0;i < TotalEnemy;i++) {
			if (enemy[i].isActive) {
				enemy[i].EnemyDraw();
			}
		}
	}
	
	
	//glTranslatef(0, 0, -10);
	



	
	
	glutSwapBuffers();
	

	
	
}


void keyboard(unsigned char key, int mousePositionX, int mousePositionY) {
	/*printf("key_code =%d  \n", key);
	int mod = glutGetModifiers();
	
		switch (key) {
		case 27:   // [ESCAPE] key
			exit(0);
			break;
		case 119:
			
			playerY_force = 0.5;
			playerForBac = 1;
			cout << "UP" << endl;
			break;
		case 115:
			playerY_force = 0.5;
			playerForBac = 2;
			cout << "DOWN" << endl;
			break;
		case 97:
			playerX_force = 0.5;
			playerLR = 2;
			cout << "LEFT" << endl;
			break;
		case 100:
			playerX_force = 0.5;
			playerLR = 1;
			cout << "RIGHT" << endl;
			break;





		default: break;
		
		
}*/
}

void CameraMoving() {
	if (GetKeyState(VK_UP) & 0x8000) {
		cam_y += 20;
	}
	if (GetKeyState(VK_DOWN) & 0x8000) {
		cam_y -= 20;
	}
	if (GetKeyState(VK_LEFT) & 0x8000) {
		cam_x -= 20;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000) {
		cam_x += 20;
	}
}
void inTitle() {
	if (GetKeyState(VK_F) & 0x8000&&MB.btnTimer<=0) {
		MB.btnTimer = 5;
		switch (MB.btnNumMenu) {
		case 0:
			fireTimer = 5;
			Scene = 1;
			break;
		case 1:
			if (MB.diffNum + 1 < 3) {
				MB.diffNum += 1;
			}
			else {
				MB.diffNum = 0;
			}
			break;
		
		case 2:
			exit(1);
			break;
		}
	}
}
void inGame() {
	for (int i = 0;i < TotalBullet;i++) {
		if (PB[i].isActive) {
			PB[i].BulletUpdate();
			if (PB[i].life > 5) {
				PB[i].life -= 1;
			}
			else {
				PB[i].BulletReset();
			}
			for (int j = 0;j < TotalEnemy;j++) {
				if (enemy[j].isActive&&PB[i].isActive) {
					if (abs(enemy[j].x - PB[i].x) <35 && abs(enemy[j].y - PB[i].y) < 35) {
						if (enemy[j].HP - PB[i].Dmg > 0) {
							enemy[j].HP -= PB[i].Dmg;
							PB[i].isShooted = true;
							PB[i].BulletReset();
							cout << "Shooted" << endl;
						}
						else {
							PB[i].isShooted = true;
							PB[i].BulletReset();
							cout << "Enemy Dead" << endl;
							enemy[j].EnemyReset();
						}
					}
				}
			}
		}
	}
	if (GetKeyState(VK_F) & 0x8000 && fireTimer <= 0) {
		fireTimer = 3;
		for (int i = 0;i < TotalBullet;i++) {
			if (!PB[i].isActive) {
				PB[i].isActive = true;
				PB[i].x = player.x + 20;
				PB[i].y = player.y + 20;
				int RandDirc = rand() % 100 + 0;
				if (player.facing == 0) {

					PB[i].y_Speed = 25;
					if (RandDirc > 50) {
					PB[i].x_Speed = rand() % 5 + 0;
					}
					else {
						PB[i].x_Speed = -rand() % 5 + 0;
					}
					break;
				}
				else if (player.facing == 1) {
					PB[i].y_Speed = -25;
					if (RandDirc > 50) {
						PB[i].x_Speed = rand() % 5 + 0;
					}
					else {
						PB[i].x_Speed = -rand() % 5 + 0;
					}
					break;
				}
				else
					if (player.facing == 2) {
						if (RandDirc > 50) {
							PB[i].y_Speed = rand() % 5 + 0;
						}
						else {
							PB[i].y_Speed = -rand() % 5 + 0;
						}
						PB[i].x_Speed = -25;
						break;
					}
					else
						if (player.facing == 3) {
							if (RandDirc > 50) {
								PB[i].y_Speed = rand() % 5 + 0;
							}
							else {
								PB[i].y_Speed = -rand() % 5 + 0;
							}
							PB[i].x_Speed = 25;
							break;
						}
			}
			cout << PB[i].x << "," << PB[i].y << endl;
		}
	}
	else {
		fireTimer -= 1;
	}
}

void update(int value) {
	glutPostRedisplay();
	player.PlayerController();
	
	switch (Scene) {
	case 0:
		CameraMoving();
		MB.TitleOper();
		inTitle();
	
		break;
	case 1:
		
		inGame();
		
		break;
	}
    glutTimerFunc(25, update, ++timerCount);
	
}


int main(int argc, char **argv) {
    std::cout << "Programmer: <your name>\n";
    std::cout << "Compiled on " << __DATE__ << ", " << __TIME__ << std::endl << std::endl;
	


    // init GLUT and create Window
    glutInit(&argc, argv);                      // GLUT initialization
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);               // set the window size

    // create the window
    glutCreateWindow("Introduction to OpenGL");

	HWND hwnd = FindWindow(NULL, "Introduction to OpenGL");
	long dyStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE;
	SetWindowLong(hwnd, GWL_STYLE, dyStyle);
	initRendering();                            // initialize rendering
	
    // register handler functions
    glutDisplayFunc(display);                   // Display function
    glutKeyboardFunc(keyboard);                 // Keyboard handler

    glutReshapeFunc(cameraSetup);               // resiz window and camera setup
    glutTimerFunc(25, update, ++timerCount);    // Timer function
	gameStart();
    glutMainLoop();                             // run GLUT mainloop
    return(0);                                  // this line is never reached
}
