#pragma once

#ifndef RECT_INC
#define RECT_INC
#include "singleGO.h"


class rect:public singleGO
{
public:
	void init();
	float color[4];
	void setCol(float r ,float g,float b,float a);
	void updateData(float x1,float y1,float x2,float y2);
	void updatePos();
	void setPos(float px,float py);
	void setRot(float rot);
	void setPosRot(float px, float py, float rot);
	void setShaders();
	rect(float x1, float y1, float x2, float y2);
	rect();
	~rect();
};

#endif