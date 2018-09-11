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
	obj->setShader(mainShader);
	objectList.push_back(obj);
	obj->me=objectList.end();
	obj->me--;
}

void render::rem(renderObject *obj)
{
	objectList.erase(obj->me);
}

render::render(shaderManager* shader)
{
	mainShader = shader;
}


render::~render()
{
}
