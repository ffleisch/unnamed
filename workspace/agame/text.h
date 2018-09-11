#pragma once
#ifndef TEXT_INC
#define TEXT_INC
#include "common.h"
#include "renderObject.h"
#include "textHelper.h"




#define START_D_ARR_LEN 32
#define START_I_ARR_LEN 32


class text:public renderObject
{
public:

	textHelper * myAtlas;
	color col;



	float* data=new float[START_D_ARR_LEN];
	GLuint* ind=new GLuint[START_I_ARR_LEN];
	int cnum = 0;
	
	float posx = 0, posy = 0;
	float rotation = 0;
	glm::mat4 transf;
	
	int elemNum = 0;
	int indNum = 0;
	
	void init();//initialisierung
	void bufferData(char* text);
	void setCol(color col);
	void updatePos();
	void setPos(float px, float py);
	void setRot(float rot);
	void setPosRot(float px, float py, float rot);

	//buffer data
	virtual void setShaderUni();
	void draw();
	//set shader settings

	text(textHelper* atlasProv);
	~text();
private:
	int dataLen = START_D_ARR_LEN;
	int indLen = START_I_ARR_LEN;
};

#endif