#include "guiNode.h"



void guiNode::updateAll()
{
	if (parent != NULL) {
		posx = parent->posx + ptransx+transx;
		posy = parent->posy + ptransy+transy;
	}else {
		posx = transx;
		posy = transy;
	}

	std::list<guiNode*>::iterator iter;
	for (iter = children.begin(); iter != children.end(); iter++) {
		(*iter)->updateAll();
	}


}

void guiNode::checkEvent(SDL_Event* e)
{
	std::list<guiNode*>::iterator iter;
	for (iter = children.begin(); iter != children.end(); iter++) {

			(*iter)->checkEvent(e);
		
	}
}

const float guiNode::toGLCordX(int x)
{
	return ((float)x/WWIDTH)*2.f-1;
}

const float guiNode::toGLCordY(int y)
{
	return (1-((float)y / WHEIGHT)*2.f);
}

void guiNode::add(guiNode * n)
{
	children.push_back(n);
	n->parent=this;
}

guiNode::guiNode()
{
}


guiNode::~guiNode()
{
}
