#pragma once
#include "renderObject.h"
class singleGO :
	public renderObject
{
public:
	float* data;
	GLuint* ind;
	float posx=0, posy=0;
	float rotation = 0;
	glm::mat4 transf;
	int elemNum=0;
	int indNum=0;
	void init();//initialisierung
	void bufferData();//buffer data
	//void updateData();//change data in array
	virtual void setShaders()=0;//set shader settings
	GLuint glMode = GL_STATIC_DRAW;
	void draw();
	singleGO();
	~singleGO();
};

