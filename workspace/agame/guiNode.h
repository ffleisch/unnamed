#pragma once

#ifndef GUINODE_INC
#define GUINODE_INC
#include "common.h"
//#include "button.h"
#include <typeinfo>
#include "render.h"
const int WWIDTH = 1024;
const int WHEIGHT = 1024;



class guiNode
{
public:

	render* guiRender;

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
	virtual void rem(guiNode* n);

	guiNode(guiNode* par);
	guiNode();
	guiNode(render * rend);

	virtual ~guiNode();
private:
	void setRendChild();
	std::list<guiNode*>::iterator me;
};

#endif