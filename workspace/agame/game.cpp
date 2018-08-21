#include "game.h"



game::game(){
	
}


game::~game(){
}

void game::init(){
	if (SDL_Init(SDL_INIT_EVERYTHING)==0) {
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	}
	else {
		throwError("Could not init SDL");
	}

	mainWindow = SDL_CreateWindow("Tha Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_OPENGL);
	if (!mainWindow) {
		throwError("Could not create Window");
	}
	mainContext = SDL_GL_CreateContext(mainWindow);

	if (glewInit()) {
		throwError("Could not init glew");
	}

	std::cout << mainContext << std::endl;
	SDL_GL_SetSwapInterval(1);
	//glViewport(0, 0, 512, 512);


}

void game::gameloop(){
	test2 = new shaderManager("./shaders/vertex.vert", "./shaders/fragment.frag");
	test = new box(0.3f, 0.1f, -0.3f, -0.1f, test2);
	box test3(-0.7,-0.7,-0.6,0,test2);
	
	while (isRunning){
		glClearColor(0, 0.5, (SDL_GetTicks()%1000)/1000.f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		test2->use();
		test->draw();
		test3.draw();
		
		SDL_GL_SwapWindow(mainWindow);

		handleInputs();

	}
}

void game::quit()
{
	
	SDL_GL_DeleteContext(mainContext);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}

void game::handleInputs()
{
	while (SDL_PollEvent(&events)) {
		if (events.type == SDL_QUIT) {
			isRunning = false;
		}
	};
}
