#include "rect.h"



void rect::init()
{
	data = new float[12];
	ind = new GLuint[6];
	elemNum = 12;
	indNum = 6;
	ind[0] = 0;
	ind[1] = 1;
	ind[2] = 3;
	ind[3] = 1;
	ind[4] = 2;
	ind[5] = 3;
	singleGO::init();
}

void rect::setCol(float r, float g, float b, float a)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;
}

void rect::updateData(float x1, float y1, float x2, float y2)
{
	data[0] = x1;
	data[1] = y1;
	data[2] = 0;
	data[3] = x1;
	data[4] = y2;
	data[5] = 0;
	data[6] = x2;
	data[7] = y2;
	data[8] = 0;
	data[9] = x2;
	data[10] = y1;
	data[11] = 0;
	bufferData();
}

void rect::setPos(float px, float py)
{
	posx = px;
	posy = py;
	updatePos();
}

void rect::setRot(float rot)
{
	rotation = rot;
	updatePos();
}

void rect::setPosRot(float px, float py, float rot)
{
	posx = px;
	posy = py;
	rotation = rot;
	updatePos();
}

void rect::updatePos()
{
	transf = glm::mat4(1.0);
	transf = glm::rotate(transf, rotation, glm::vec3(0, 0, 1));
	transf = glm::translate(transf,glm::vec3(posx,posy,0.f));
}

void rect::setShaders()
{
	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "transform"),1,GL_FALSE,glm::value_ptr(transf));
	glUniform4f(glGetUniformLocation(shader->ID, "col"), color[0], color[1], color[2], color[3]);
}

rect::rect(float x, float y, float w, float h)
{
	init();
	posx = x;
	posy = y;
	updatePos();
	updateData(-w/2.f,-h/2.f,w/2.f,h/2.f);
	//setCol(0,0,0,0);
}

rect::rect()
{
	init();
}


rect::~rect()
{
}
