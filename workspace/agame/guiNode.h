#pragma once

#ifndef GUINODE_INC
#define GUINODE_INC
#include "common.h"
//#include "button.h"
#include <typeinfo>
const int WWIDTH = 1024;
const int WHEIGHT = 1024;



class guiNode
{
public:

	std::list<guiNode*> children;
	guiNode* parent;
	float posx, posy;
	float transx, transy;
	float ptransx, ptransy;
	bool isRoot = false;

	virtual void updateAll();
	virtual void checkEvent(SDL_Event* e);
	const float toGLCordX(int x);
	const float toGLCordY(int y);
	virtual void add(guiNode* n);

	guiNode();
	virtual ~guiNode();
};

#endif