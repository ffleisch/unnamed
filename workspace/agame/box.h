#pragma once
#ifndef BOX_INC
#define BOX_INC
#include "renderObject.h"
#include "shaderManager.h"
#include "common.h"

class box:public renderObject
{
public:
	shaderManager* shader;
	float vertices[12];
	GLuint indices[6];
	float color[4];
	void draw();
	void setCoords(float x1, float y1, float x2, float y2);
	void setCol(float red, float green, float blue, float alpha);
	box(float x1,float y1, float x2,float y2,shaderManager *myShader);
	~box();
};

#endif 
