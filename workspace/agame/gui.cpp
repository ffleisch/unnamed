#include "gui.h"



void gui::update()
{
	root.updateAll();
}

void gui::checkEvents(SDL_Event * e)
{
	root.checkEvent(e);
}

gui::gui(shaderManager* buttonShader):guiRender(buttonShader),root(&guiRender)
{

}


gui::~gui()
{

}
