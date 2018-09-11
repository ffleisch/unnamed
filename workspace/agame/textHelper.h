#pragma once

#ifndef TEXTHELPER_INC
#define TEXTHELPER_INC

#include <ft2build.h>
#include FT_FREETYPE_H

#include "Error.h"
#include <algorithm>
#include "shaderManager.h"
struct character {
	glm::ivec2 size;
	glm::ivec2 bearing;
	glm::ivec2 advance;
	glm::ivec2 atPos;
};

class textHelper
{
public:
	 shaderManager * textShader;
	 character myChars[128];
	 bool isInit=false;
	 FT_Library ftLib;
	
	 GLuint atW=0,atH=0;

	 glm::mat4 projection;

	 int* windowWidth;
	 int* windowHeight;

	 void setShader(shaderManager* man);

	GLuint textureID;

	textHelper(const char * path,int* w,int* h);
	textHelper(const char * path,int* w,int*h , int height);
	~textHelper();
};

#endif // !TEXTHELPER_INC
