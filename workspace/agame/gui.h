#pragma once
#ifndef GUI_INC
#define GUI_INC
#include "guiNode.h"
#include "common.h"
class gui
{
public:
	//virtual void render()=0;
	guiNode root;
	void update();
	gui();
	~gui();
};

#endif // !GUI_INC