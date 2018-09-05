#pragma once

#ifndef BUTTON_INC
#define BUTTON_INC
#include "guiNode.h"
#include "rect.h"

class button :
	public guiNode
{
public:
	rect img;
	float width, height;
	bool state=false;
	bool isPressed = false;
	void (*onClick)();
	int num=-1;
	color hoverCol=color(.5);
	color normCol = color(.7);
	color pressCol = color(0.3,0.3,1.0);
	button(float width,float height,guiNode* par);
	
	virtual void updateAll();

	virtual void checkEvent(SDL_Event* e);
	void setCol(float r, float g, float b, float a);

	~button();
private:
	bool isInside(float x,float y);
	bool isInside(int x, int y);
};

#endif