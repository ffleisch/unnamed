#include "game.h"



game::game(){
}


game::~game(){
}

void game::init(){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* wind = SDL_CreateWindow("Tha Game", 100, 100, 500, 300, SDL_WINDOW_OPENGL);
}

void game::gameloop(){
	SDL_Event *test = new SDL_Event;
	while (isRunning){
		SDL_PollEvent(test);
	}
}
