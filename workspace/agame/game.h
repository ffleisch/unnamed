#pragma once
#include "common.h"
#ifndef GAME_INC
#define GAME_INC

enum gamestate {menu,running,paused,loading};

class game
{
public:
	gamestate state = menu;
	bool isRunning = true;

	SDL_Window* mainWindow=NULL;


	game();
	~game();

	void init();
	void gameloop();

};
#endif
