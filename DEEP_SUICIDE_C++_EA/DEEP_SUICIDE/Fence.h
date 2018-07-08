#include "GL/freeglut.h"
#include <string>

#pragma once
class Fence
{
public:
	Fence();
	~Fence();

public:
	GLuint TexID[1];
	bool isActive = true;

public:
	void DrawFenceY();
	void DrawFenceX();
	void FenceInit();
};

