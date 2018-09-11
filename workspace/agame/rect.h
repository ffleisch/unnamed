#pragma once

#ifndef RECT_INC
#define RECT_INC
#include "singleGO.h"


class rect:public singleGO
{
public:
	void init();
	color rColor;
	void setCol(float r ,float g,float b,float a);
	void setCol(color col);
	void updateData(float x1,float y1,float x2,float y2);
	void updatePos();
	void setPos(float px,float py);
	void setRot(float rot);
	void setPosRot(float px, float py, float rot);
	virtual void setShaderUni();


	rect(float x, float y, float w, float h);


	rect();
	~rect();
};

#endif