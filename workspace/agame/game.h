#pragma once
#include "common.h"
#include "Error.h"
#include "box.h"
#include "render.h"
#include "rect.h"
#include "button.h"
#include "vbox.h"
#ifndef GAME_INC
#define GAME_INC

enum gamestate {menu,running,paused,loading};

class game
{
public:

	shaderManager* test2;
	guiNode* mNode;
	render* mainRender;
	gamestate state = menu;
	bool isRunning = true;

	SDL_Window* mainWindow=NULL;
	SDL_GLContext mainContext;

	game();
	~game();

	void init();
	void gameloop();
	void quit();

	void handleInputs();
private:
	SDL_Event events;

};
#endif
