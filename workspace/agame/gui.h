#pragma once
#ifndef GUI_INC
#define GUI_INC
#include "guiNode.h"
#include "common.h"
class gui
{
public:
	bool isEnabled = true;
	render guiRender;
	guiNode root;
	virtual void update();
	virtual void checkEvents(SDL_Event* e);
	gui(shaderManager* buttonRender);
	~gui();
};

#endif // !GUI_INC