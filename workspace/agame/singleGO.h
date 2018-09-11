#pragma once
#include "renderObject.h"


//einzelnes objekt das zum renderer hinzugefügt werden kann

//kann vertices in data als dreiecke anzeigen
//ruft in draw() genau einmal glDrawElements auf

class singleGO :
	public renderObject
{
public:
	GLuint mode = GL_STATIC_DRAW;

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
	virtual void setShaderUni()=0;//set shader settings
	GLuint glMode = GL_STATIC_DRAW;
	void draw();
	singleGO();
	singleGO(GLuint drawMode);
	~singleGO();
};

