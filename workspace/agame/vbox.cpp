#include "vbox.h"



vbox::vbox(guiNode* par):guiNode(par)
{
}

void vbox::updateAll() {
	std::list<guiNode*>::iterator iter;
	int i = 0;
	for (iter = children.begin(); iter != children.end(); iter++) {
		(*iter)->ptransy=(float)i*spacing;
		i++;
	}
	guiNode::updateAll();

}

vbox::~vbox()
{
}
