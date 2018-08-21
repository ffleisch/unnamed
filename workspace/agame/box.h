#pragma once
#ifndef BOX_INC
#define BOX_INC
#include "renderObject.h"
#include "shaderManager.h"
#include "common.h"

class box:renderObject
{
public:
	shaderManager* shader;
	float vertices[12];
	void draw();
	box(float x1,float y1, float x2,float y2,shaderManager *myShader);
	~box();
};

#endif 
