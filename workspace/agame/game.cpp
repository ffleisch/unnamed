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

	mainWindow = SDL_CreateWindow("Tha Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 1024, SDL_WINDOW_OPENGL);
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
	mainRender=new render(test2);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//rect test(0,0, 1 ,.1);
	//test.shader = test2;
	button* btn;
	mNode = new guiNode();
	vbox* theBox = new vbox();
	theBox->spacing = 0.06;
	theBox->transy = -5 * theBox->spacing;
	for (int i = 0; i < 10; i++) {
		btn = new button(0.5, 0.05, NULL);
		btn->setCol(1, 0, 0, 0);
		//btn->transy = 0.5f-(float)0.1f*i;
		btn->num = i;
		//btn->onClick = &testFunc;
		theBox->add(btn);
		mainRender->add(&btn->img);
	}
	mNode->add(theBox);
	mNode->updateAll();

	while (isRunning){
		
		glClearColor(0,0,0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		
		mainRender->drawAll();

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
		mNode->checkEvent(&events);
		if (events.type == SDL_QUIT) {
			isRunning = false;
		}
	};
}
