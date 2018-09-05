#pragma once
#ifndef RENDEROBJECT_INC
#define RENDEROBJECT_INC
#include "common.h"
#include "shaderManager.h"
class renderObject
{

public:
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
	std::list<renderObject*>::iterator me;
	shaderManager* shader;
	void setShader(shaderManager* m);
	virtual void draw()=0;
	renderObject();
	~renderObject();
};
#endif // !RENDEROBJECT_INC

