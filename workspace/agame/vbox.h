#pragma once


#ifndef VBOX_INC
#define VBOX_INC
#include "guiNode.h"

class vbox:public guiNode
{
public:
	float spacing=0.1;
	vbox();
	virtual void updateAll();
	~vbox();
};

#endif