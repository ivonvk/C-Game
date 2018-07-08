#include "GL/freeglut.h"
#include <string>

#pragma once
class Floor
{
public:
	Floor();
	~Floor();

public:
	GLuint TexID[1];
	float counter = 100;
	int numImg = 0;

public:
	void DrawFloorX();
	void FloorInit();
	void FloorUpdata();
};

