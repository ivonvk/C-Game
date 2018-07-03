/*  Filename:       main.cpp
    Description:    MET4335 - Lab05
*/
#include "GL/freeglut.h"
#include <windows.h>  // include all the windows headers
#include<windowsx.h>
#include "MenuButton.h"
#include "GameSceneUI.h"
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

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

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
int Wave = 1;
int mouse_x, mouse_y;
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
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);                // select projection matrix
    glLoadIdentity();                           // reset projection matrix
    //gluPerspective(100.0, 1, 1.0, 100.0);        // set up a perspective projection matrix
	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
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

	//TOP outside tile
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1);
	glVertex3f(0, 800, 0.2);
	glVertex3f(0, 740, 0.2);
	glVertex3f(800, 740, 0.2);
	glVertex3f(800, 800, 0.2);
	glEnd();

	//TOP inside tile
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.3);
	glVertex3f(10, 790, 0.3);
	glVertex3f(10, 750, 0.3);
	glVertex3f(790, 750, 0.3);
	glVertex3f(790, 790, 0.3);
	glEnd();
	//text
	glColor3f(1, 0, 0);
	glRasterPos3f(330, 760,0.4);
	string Title = "SUICIDE DEEPLY";
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)Title.c_str());

	//Right
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(800, 0, 0.2);
	glVertex3f(320, 0, 0.2);
	glVertex3f(800, 200, 0.2);
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



	//640W,480H; WC 320; HC 240;
	//Draw Player Home
	glPushMatrix();
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3f(220, 140, 0);
	glVertex3f(420, 140, 0);
	glVertex3f(420, 340, 0);
	glVertex3f(220, 340, 0);
	glEnd();
	glPopMatrix();



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
void MousePos(int x, int y) {
	mouse_x = x;
	mouse_y = 480 - y;

}
void inGame() {
	for (int i = 0;i < 150;i++) {
		if (enemy[i].isActive) {
			enemy[i].EnemyUpdate(player.x, player.y);
			if (abs(enemy[i].x - player.x) <40&& abs(enemy[i].y - player.y) <40){
				if (enemy[i].atkSpeed <= 0) {
					cout << "Enemy Attack Player" << endl;
					GSUI.TOPUIUPDATE(enemy[i].Dmg, 1);
					enemy[i].atkSpeed = 5.0f;
				}
			}
			
		}

	}
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
					if (abs(enemy[j].x - PB[i].x) <35 && abs(enemy[j].y - PB[i].y) <35) {
						if (enemy[j].HP - PB[i].Dmg > 0) {
							enemy[j].HP -= PB[i].Dmg;
							
							PB[i].life = 1.2;
							cout << "Shooted" << endl;
						}
						else {
						
							PB[i].life = 1.2;
							cout << "Enemy Dead" << endl;
							enemy[j].EnemyReset();
						}
					}
				}
			}
		}
	}
	if (GetKeyState(VK_F) & 0x8000 && fireTimer <= 0) {
		fireTimer = 6;
		for (int i = 0;i < TotalBullet;i++) {
			if (!PB[i].isActive) {
				
				PB[i].isActive = true;
				if (PB[i].isActive) {
					PB[i].x = player.x+20;
					PB[i].y = player.y+20;
					int randNum = rand() % 100 + 1;
					if (player.facing == 0) {
						if (randNum > 50) {
							PB[i].x_Speed = -rand() % 3+ 0.2f;
						}else {
							PB[i].x_Speed = rand() % 3 + 0.2f;
						}
						PB[i].y_Speed = 20;
					
					}
					else if (player.facing == 1) {
						if (randNum > 50) {
							PB[i].x_Speed = -rand() % 3 + 0.2f;
						}
						else {
							PB[i].x_Speed = rand() % 3 + 0.2f;
						}
						PB[i].y_Speed = -20;
					}
					else if (player.facing == 2) {
						if (randNum > 50) {
							PB[i].y_Speed = -rand() % 3 + 0.2f;
						}
						else {
							PB[i].y_Speed = rand() % 3 + 0.2f;
						}
						PB[i].x_Speed = -20;
					}
					else if (player.facing == 3) {
						if (randNum > 50) {
							PB[i].y_Speed = -rand() % 3 + 0.2f;
						}
						else {
							PB[i].y_Speed = rand() % 3 + 0.2f;
						}
						PB[i].x_Speed = 20;
					}
				}
				break;
			}
			
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
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);               // set the window size

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
	glutPassiveMotionFunc(MousePos);
	gameStart();
    glutMainLoop();                             // run GLUT mainloop
    return(0);                                  // this line is never reached
}
