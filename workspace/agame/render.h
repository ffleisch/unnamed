#pragma once
#include "common.h"
#include "renderObject.h"

class render
{
public:
	shaderManager* mainShader;
	std::list<renderObject*> objectList;

	void drawAll();
	void add(renderObject *obj);
	void rem(renderObject *obj);
	render(shaderManager* shader);
	~render();
};

