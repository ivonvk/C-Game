#include "CustomImage.h"
#include <fstream>
#include <iostream>

using namespace std;


CustomImage::CustomImage()
{
}

CustomImage::~CustomImage()
{
}

CustomImage::CustomImage(const char*fileName) {
	LoadBitmapImage(fileName);
}


int CustomImage::GenTexture() {
	GLuint texID;
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

	return texID;
}



void CustomImage::LoadBitmapImage(const char * fileName)
{
	FILE *file = fopen(fileName, "rb");
	if (file == NULL) {
		cout << "Fail to open file!" << endl;
		return;
	}

	fread(header, 1, 54, file);
	if (header[0] != 'B' || header[1] != 'M') {
		cout << "Wrong file format!" << endl;
		return;
	}

	dataPos = *(int*)&header[0xA];
	imageSize = *(int*)&header[0x22];
	width = *(int*)&header[0x12];
	height = *(int*)&header[0x16];

	if (imageSize == 0) {
		imageSize = width*height * 3;
	}
	if (dataPos = 0) {
		dataPos = 54;
	}

	data = (unsigned char*)malloc(imageSize);
	fread(data, 1, imageSize, file);

	fclose(file);

}



