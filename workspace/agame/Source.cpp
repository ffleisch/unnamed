#include "common.h"
#include "game.h"
#include "Error.h"
int main(int argc, char *args[]) {
	game myGame;
	myGame.init();
	myGame.gameloop();
	return(42);
}