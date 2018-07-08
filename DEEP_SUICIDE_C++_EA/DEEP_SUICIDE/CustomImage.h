#pragma once
#include "GL\freeglut.h"
class CustomImage
{
public:
	CustomImage();
	~CustomImage();
	CustomImage(const char*fileName);
public:
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int width, height;
	unsigned int imageSize;

	unsigned char * data;

	GLuint texID;

public:
	void LoadBitmapImage(const char * fileName);
	int GenTexture();

};

