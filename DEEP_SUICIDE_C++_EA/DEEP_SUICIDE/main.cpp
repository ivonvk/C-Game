/*  Filename:       main.cpp
    Description:    MET4335 - Lab05
*/


#include <dsound.h>
#include <vector>

#include <windows.h>
#include <mmsystem.h>
#include <process.h>
#include "GL/freeglut.h"
#include "Item_Pickup.h"
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
#include "CustomImage.h"
#include "Floor.h"
#include "Fence.h"


#define VK_W 87
#define VK_S 83
#define VK_A 65
#define VK_D 68
#define VK_F 70

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define SOUND_NULL          0 
#define SOUND_LOADED        1
#define SOUND_PLAYING_LOOP  2
#define SOUND_PLAYING_ALON  3
#define SOUND_STOPPED       4

using namespace std;

float musicPlayer;
int Scene = 0;

int TopDoor = 5000;
int BottomDoor = 5000;
int LeftDoor = 5000;
int RightDoor = 5000;

int TotalBullet = 200;
int TotalEnemy;
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
int enemyNum = 0;
int Wave = 1;
int mouse_x, mouse_y;
float fireTimer;
float fireSoundTimer;
bool isPreparing;
Player player;
PlayerBullet *PB;
MenuButton MB;
GameSceneUI inGameUI;
Enemy *enemy ;
Item_Pickup objItem[100];
Fence fencei;
Floor floors;

float WaveStartCounter = 500;



void Fire1(void *argu) {
	mciSendString("play Sound/a_1.mp3", NULL, 0, NULL);


	cout << "Fire1" << endl;
	_endthread();
}
void Fire2(void *argu) {
	mciSendString("play Sound/a_2.mp3", NULL, 0, NULL);


	cout << "Fire2" << endl;
	_endthread();
}


/*DWORD WINAPI Fire1(PVOID pvParam)
{

	mciSendString("play Sound/a_2.mp3", NULL, 0, NULL);

	
	cout << "Fire1" << endl;


	return 0;
}
DWORD WINAPI Fire2(PVOID pvParam)
{


		mciSendString("play Sound/a_1.mp3", NULL, 0, NULL);
		//mciSendString("close Sound/q_1.mp3", NULL, 0, NULL);



	cout << "Fire2" << endl;


	return 0;
}*/



DWORD WINAPI MyThread2(PVOID pvParam)
{
	
	//mciSendString("play music.wav", NULL, 0, NULL);
	PlaySound("music.wav", NULL, SND_FILENAME | SND_ASYNC);

		
	
	return 0;
}






void initRendering() {
    glEnable(GL_DEPTH_TEST);                    // test 3D depth
	floors.FloorInit();
	player.PlayerInit();
	fencei.FenceInit();

	for (int i = 0; i < 150; i++) {
	objItem[i].ItemInit();
	}
}

void gameStart() {


	PB = new PlayerBullet[200];
	//PLAYER START LOCATION
	if (Wave == 1) {
		player.x = 383;
		player.y = 420;
	}
	TotalEnemy = Wave * 4;
	enemy = new Enemy[Wave * 4];
	//ENEMY SPAWNING
	if (enemyNum < Wave * 4) {
		for (int i = 0;i < Wave * 4;i++) {
			enemy[i] = *new Enemy;
			if (!enemy[i].isActive) {
				enemy[i].isActive = true;
				//ENEMY LOCATION RANDOMLY
				enemy[i].x = -rand() % 1000 + 280;
				enemy[i].y = -rand() %1000 + 280;
			}
		}
		for (int i = 0;i < Wave * 10;i++) {
			objItem[i].isActive = true;
			//ITEM SPWANING LOCATION AND TYPE RANDOMLY
			int RandItem = rand() % 100 + 1;
			if (RandItem > 70) {
				objItem[i].x = rand() % 200 + 0;
				objItem[i].y = rand() % 450 +50;
				objItem[i].iType = 0;
			}
			else if(RandItem >50){
				objItem[i].x = rand() % 500 + 450;
				objItem[i].y = rand() % 450 + 50;
				objItem[i].iType = 1;
			}
			else {
				objItem[i].x = rand() % 200 + 0;
				objItem[i].y = rand() % 450 + 50;
				objItem[i].iType = 2;
			}
		}
	}
}
void gameWaveChecking() {

		
	
			Wave += 1;
			gameStart();
			
		
	
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
	//TOP outside tile
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 1);
	glVertex3f(0, 800, 0.2);
	glVertex3f(0, 740, 0.2);
	glVertex3f(800, 740, 0.2);
	glVertex3f(800, 800, 0.2);
	glEnd();
	glPopMatrix();

	//TOP inside tile
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.3);
	glVertex3f(10, 790, 0.3);
	glVertex3f(10, 750, 0.3);
	glVertex3f(790, 750, 0.3);
	glVertex3f(790, 790, 0.3);
	glEnd();
	glPopMatrix();


	//TITLE TEXT
	glPushMatrix();
	glColor3f(1, 0, 0);
	glRasterPos3f(330, 760,0.4);
	string Title = "SUICIDE DEEPLY";
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)Title.c_str());
	//Left POLYGON
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.0, 0.0);
	glVertex3f(0, 0, 0.2);
	glVertex3f(0, 400, 0.2);
	glVertex3f(400, 0, 0.2);
	glEnd();
	glPopMatrix();


	//Right POLYGON
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(800, 0, 0.2);
	glVertex3f(400, 0, 0.2);
	glVertex3f(800, 400, 0.2);
	glEnd();
	glTranslatef(0, -10, 0);
	glPopMatrix();

	//GameStartButton
	
		glPushMatrix();
		glTranslatef(270,420, 0);
		MB.StartButton();

		glTranslatef(0, -80, 0);
		MB.DifficultButton();

		glTranslatef(0, -80, 0);
		MB.QuitButton();

		glPopMatrix();
	



}

void display() {
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear Screen and Depth Buffer
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();




	//640W,480H; WC 320; HC 240;
	//Draw Player Home
	glPushMatrix();
	glTranslatef(255,306, 0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 280, 0);
	glVertex3f(280, 280, 0);
	glVertex3f(280, 0, 0);
	glEnd();
	glPopMatrix();


	//Draw Wall Block Left
	glPushMatrix();
	glTranslatef(220,305,0);
	fencei.DrawFenceY();
	glTranslatef(0, 94, 0);
	fencei.DrawFenceY();
	glTranslatef(0, 94, 0);
	fencei.DrawFenceY();
	glPopMatrix();

	//Draw Wall Block Right
	glPushMatrix();
	glTranslatef(535, 305, 0);
	fencei.DrawFenceY();
	glTranslatef(0, 94, 0);
	fencei.DrawFenceY();
	glTranslatef(0, 94, 0);
	fencei.DrawFenceY();
	glPopMatrix();

	//Draw Wall Block Bot
	glPushMatrix();
	glTranslatef(220, 270, 0);
	fencei.DrawFenceX();
	glTranslatef(70, 0, 0);
	fencei.DrawFenceX();
	glTranslatef(70, 0, 0);
	fencei.DrawFenceX();
	glTranslatef(70, 0, 0);
	fencei.DrawFenceX();
	glTranslatef(70, 0, 0);
	fencei.DrawFenceX();
	glPopMatrix();

	//Draw Wall Block Top
	glPushMatrix();
	glTranslatef(220, 585, 0);
	fencei.DrawFenceX();
	glTranslatef(70, 0, 0);
	fencei.DrawFenceX();
	glTranslatef(70, 0, 0);
	fencei.DrawFenceX();
	glTranslatef(70, 0, 0);
	fencei.DrawFenceX();
	glTranslatef(70, 0, 0);
	fencei.DrawFenceX();
	glEnd();
	glPopMatrix();

	//Draw Floor
	for (int y = 0; y < 800; y += 50) {
		glTranslatef(0, y, -0.1);
		floors.DrawFloorX();
		glLoadIdentity();
	}

	//IF PLAYER ENTER THE FIRST SCENE OF GAME SHOULD BE START SCENE MENU AND DRAWING UI
	if (Scene == 0) {
		StartSceneMenu();
		inGameUI.MID_SCENE_UI_DRAW();
	}
	//IF PLAYER START THE GAME THEN DRAWING UI PLAYER ENEMY AND OBJECT
	if (Scene != 0) {
		inGameUI.MID_SCENE_UI_DRAW();
		inGameUI.TOP_UI_DRAW();

		//DRAWING PLAYER IF MOVING
		glPushMatrix();
		glTranslatef(player.x, player.y, 0);
		player.PlayerDraw();
		glPopMatrix();

		for (int i = 0;i < Wave * 10;i++) {
			if (objItem[i].isActive) {
				//GIVE A LOCAL TRANSLATE TO EVERY ITEM AND SET LOCATION OF THEM
				glPushMatrix();
				glTranslatef(objItem[i].x, objItem[i].y, 0);
				objItem[i].ItemDraw();
				glPopMatrix();
			}
		}
		for (int i = 0;i < TotalBullet;i++) {
			//DRAWING BULLET FLYING IF SHOOTED
			if (PB[i].isActive) {
				PB[i].BulletDraw();
			}
		}
		for (int i = 0;i < Wave*4;i++) {
			if (enemy[i].isActive) {
				//DRAWING ENEMY MOVING
				glPushMatrix();
				glTranslatef(enemy[i].x, enemy[i].y, 0);
				enemy[i].EnemyDraw();
				glPopMatrix();
			}
		}
	}

	glutSwapBuffers();
}


void keyboard(unsigned char key, int mousePositionX, int mousePositionY) {
}

void inTitle() {
	//CONFIRM PLAYER PRESS BUTTON 
	/*	THE FIRST BUTTON CASE 0 IS START GAME
		THE SECOND BUTTON CASE 1 IS SET THE GAME MODE
		THE THIRD BUTTON CASE 2 IS QUIT THE GAME	*/
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


	//CHECK EVERY ITEM AND GET IF PLAYER NEARBY THEM
	for (int i = 0;i < Wave * 10;i++) {
		if (objItem[i].isActive) {
			if (abs(objItem[i].x - player.x) < 42 && abs(objItem[i].y - player.y) < 42) {
				switch (objItem[i].iType) {
					/*	ITEM 0 CASE 0 IS GET MORE AMMO
						ITEM 1 CASE 1 IS RESTORE PLAYER HP
						ITEM 2 CASE 2 IS GET RESOURCES TO REPAIR HOUSE	*/
				case 0:
					if (player.MaxAmmo + 20 <= 100) {
						player.MaxAmmo += 20;
						objItem[i].isActive = false;
					}
					break;
				case 1:
					if (inGameUI.Draw_iPlayerHP + 10 < 100) {
						inGameUI.Draw_iPlayerHP += 10;
						objItem[i].isActive = false;
					}
					else if (inGameUI.Draw_iPlayerHP > 91&& inGameUI.Draw_iPlayerHP < 100) {
						inGameUI.Draw_iPlayerHP =100;
						objItem[i].isActive = false;
					}
						
					
					break;
				case 2:
					glColor3f(1, 1, 0);
					break;
				}
			}
		}
	}
	//DETECT ENEMY AND BLOCK IF THEY TRY TO ENTER THE HOUSE
	for (int i = 0;i < Wave * 4;i++) {
		if (enemy[i].isActive) {
			enemy[i].soundCounter -= 1;
			//TOP AND RIGHT BOX BLOCKING ENEMY
			
				//KNOCKBACK ENEMY
			if (enemy[i].y > 250&& enemy[i].y < 350) {
				if (enemy[i].x < 600 && enemy[i].x > 200) {
				
					if (BottomDoor - enemy[i].Dmg >= 0) {
						BottomDoor -= enemy[i].Dmg;

						enemy[i].y -= 8;

					}
					else {
						enemy[i].EnemyUpdate(player.x, player.y);
					}
				}
				else {
					enemy[i].EnemyUpdate(player.x, player.y);
				}
			}
			else if (enemy[i].y > 600&& enemy[i].y < 630) {
				if (enemy[i].x < 600 && enemy[i].x > 200) {
				
					if (TopDoor - enemy[i].Dmg >= 0) {
						TopDoor -= enemy[i].Dmg;

						enemy[i].y += 8;

					}
					else {
						enemy[i].EnemyUpdate(player.x, player.y);
					}
				}
				else {
					enemy[i].EnemyUpdate(player.x, player.y);
				}
			}
			else if (enemy[i].x > 180 && enemy[i].x < 280) {
				if (enemy[i].y < 600 && enemy[i].y > 200) {
				
					if (LeftDoor - enemy[i].Dmg >= 0) {
						LeftDoor -= enemy[i].Dmg;

						enemy[i].x -= 8;

					}
					else {
						enemy[i].EnemyUpdate(player.x, player.y);
					}
				}
				else {
					enemy[i].EnemyUpdate(player.x, player.y);
				}
			}
			else if (enemy[i].x > 510 && enemy[i].x < 610) {
				if (enemy[i].y < 600 && enemy[i].y > 200) {
			
					if (RightDoor - enemy[i].Dmg >= 0) {
						RightDoor -= enemy[i].Dmg;

						enemy[i].x += 8;

					}
					else {
						enemy[i].EnemyUpdate(player.x, player.y);
					}
				}
				else {
					enemy[i].EnemyUpdate(player.x, player.y);
				}
			}
			else {
				enemy[i].EnemyUpdate(player.x, player.y);
			}
			
				
		
			
			
			
			
			//DETECT IF ENEMY NEARBY PLAYER AND GIVE DAMAGE TO HIM
			if (abs(enemy[i].x - player.x ) <42&& abs(enemy[i].y - player.y) <42){
				if (enemy[i].atkSpeed <= 0) {
					
			
					inGameUI.TOP_UI_UPDATE(enemy[i].Dmg, Wave,player.Ammo, player.MaxAmmo,player.Reloading);
					enemy[i].atkSpeed = 5.0f;
				}
			}
			for (int s = 0;s < TotalEnemy;s++) {
				if (abs(enemy[i].x - enemy[s].x) <40 && abs(enemy[i].y - enemy[s].y) <40) {
					int x, y;
					int RandX = rand() % 100 + 1;
					int RandY = rand() % 100 + 1;
					int RandOfEne = rand() % 100 + 1;
					if (RandX > 50 ? x =20 : x = -20);
					if (RandY > 50 ? y = 20 : y = -20);
					//enemy[i].x += x;
						//enemy[i].y += y;
						enemy[i].speed = 2;
						
						if (enemy[i].soundCounter <= 0) {
							//enemy[i].playSound();
							
							enemy[i].soundCounter =rand()%125+75;
							
						
						}
				}
				else {
					enemy[i].speed = 5;
				}
			}
		}

	}
	//EVERY BULLET OPERATING
	for (int i = 0;i < TotalBullet;i++) {
		//BULLET RESET AFTER SHOOTED
		if (PB[i].life > 1) {
			PB[i].life -= 0.3;
		}
		else {
			PB[i].isFired = false;
		}
		if (PB[i].isActive) {
			
			for (int j = 0;j < Wave*4;j++) {
				if (enemy[j].isActive && !PB[i ].isFired) {
					//IF BULLET SHOOTED AND NEARBY ENEMY THEN DO FUNCTION
					if (abs(enemy[j].x - PB[i].x) < 35 && abs(enemy[j].y - PB[i].y) < 35) {
						//GIVE DAMAGE TO ENEMY IF ENEMY HP LAGRE THEN THE DAMAGE
						if (enemy[j ].HP - PB[i ].Dmg > 0) {
							PB[i].life = 0.5;
							enemy[j ].HP -= PB[i ].Dmg;
						
							PB[i].isFired = true;
							PB[i].isActive = false;
							
							
						}
						//ENEMY DEAD IF DAMAGE LAGRE THEN ENEMY HP
						else {
								PB[i ].life = 0.5;
							
								enemy[j ].EnemyReset();
								PB[i].isFired = true;
								PB[i].isActive = false;
								TotalEnemy -= 1;
								if (TotalEnemy <= 0) {
									TotalEnemy = 0;
									delete [] enemy;
									WaveStartCounter = 500;
								}
						}
						
					}


				}

			}
		}
		//BULLET FLYING IF NOTHINGS DETECTED
		PB[i].BulletUpdate();
	}
	//PLAYER RELOAD AMMO TIMER
	if (player.Reloading > 0) {
		player.Reloading -= 1;
	}
	bool guned = false;
	//PRESS F AND FIRETIMER IS 0 THEN SPAWN BULLET TO DIRCTION WHICH IS PLAYER FACING OF 
	if (GetKeyState(VK_F) & 0x8000 && fireTimer <= 0) {
		//IF PLAYER AT LEAST HAS 1 AMMO THEN DO FUNCTION
		if (player.Ammo - 1 >= 0) {
			//IF PLAYER RELOAD AMMO TIMER IS 0 THEN DO ACTION
			if (player.Reloading <= 0) {
				fireTimer = 7.5;
				
				//DECREASE AMMO
				player.Ammo -= 1;
				//SET FIRE RATE DELAY
				
				
				//DECIDE BULLET DIRCTION AND RANDOM FIRE LINE
				
				for (int i = 0;i < TotalBullet;i++) {
					
					if (!PB[i].isActive) {
						cout << PB[i].isFired << endl;
						PB[i].isActive = true;
						if (PB[i].isActive) {
							if (player.Ammo % 2 == 0) {
								//HANDLE hFire1 = (HANDLE)_beginthread( Fire1, 0, NULL);
								HANDLE hFire1 = (HANDLE)_beginthread(Fire1, 0, NULL);

							}
							else {
								//HANDLE hFire2 = CreateThread(NULL, 0, Fire2, NULL, 0, NULL);
								HANDLE hFire2 = (HANDLE)_beginthread(Fire2, 0, NULL);

							}
							PB[i].x = player.x + 20;
							PB[i].y = player.y + 20;
							int randNum = rand() % 100 + 1;
							if (player.facing == 0) {
								if (randNum > 50) {
									PB[i].x_Speed = -rand() % 3 + 0.2f;
								}
								else {
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
		

			
		}
		//IF AMMO IS 0 AMMO WILL GET 10 OF MAX AMMO TO BE AMMO
		else {
			if (player.MaxAmmo - 20 >= 0) {
				player.Ammo += 20;
				player.MaxAmmo -= 20;
				player.Reloading = 50;
			}

		}
		
	}
	//IF FIRE RATE IS NOT READY THEN DECRASING
	
	if(fireTimer>0) {
		
		fireTimer -= 1;
	}
	
}

void update(int value) {
	if (musicPlayer <= 0) {
		HANDLE hThread2 = CreateThread(NULL, 0, MyThread2, NULL, 0, NULL);
		musicPlayer = 2000;
	
		CloseHandle(hThread2);
	}
	else {
		musicPlayer -=1;
	}


	glutPostRedisplay();
	player.PlayerUpdata();
	//floors.FloorUpdata();

	player.PlayerMoving();
	inGameUI.TOP_UI_UPDATE(0, Wave, player.Ammo,player.MaxAmmo, player.Reloading);
	
	//DETECT SCENE AND DO FUNCTION
	switch (Scene) {
	case 0:
		MB.TitleOper();
		inTitle();
		break;
	case 1:
		if (WaveStartCounter > 50) {
			WaveStartCounter -= 25;
		}
		else if (WaveStartCounter > 25)
		{
			WaveStartCounter -= 5;
				
			
		}
		else {
			if (TotalEnemy <= 0) {
				gameWaveChecking();
				
				WaveStartCounter = 0;
			}
			if (TotalEnemy > 0) {
				inGame();
				inGameUI.MID_UI_UPDATE(TopDoor, BottomDoor, LeftDoor, RightDoor);
			}
		}
		
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

	gameStart();
    glutMainLoop();                             // run GLUT mainloop
    return(0);                                  // this line is never reached
}
