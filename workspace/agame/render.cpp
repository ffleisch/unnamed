#include "render.h"



void render::drawAll()
{
	std::list<renderObject*>::iterator iter;
	for (iter = objectList.begin(); iter != objectList.end(); iter++) {
		(*iter)->draw();
	}
}

void render::add(renderObject *obj)
{
	objectList.push_back(obj);
	obj->me=objectList.end();
}

void render::rem(renderObject *obj)
{
	objectList.erase(obj->me);
}

render::render()
{
}


render::~render()
{
}
