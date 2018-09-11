#include "game.h"



game::game(){
	
}


game::~game(){
}

void game::init(){
	if (SDL_Init(SDL_INIT_EVERYTHING)==0) {
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
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
	windowHeight = 1024;
	windowWidth = 1024;


}

void game::gameloop(){
	//ttest = new textHelper("./fonts/Apex-mk2/ApexMk2-Regular.otf", &windowHeight, &windowWidth,50);
	ttest = new textHelper("./fonts/WolveSymbol.ttf", &windowHeight, &windowWidth, 48);
	textHelper* ttest2 = new textHelper("./fonts/Open 24 Display St.ttf", &windowHeight, &windowWidth, 48);
	textHelper* ttest3 = new textHelper("./fonts/GhastlyPixe.ttf", &windowHeight, &windowWidth, 48);


	test2 = new shaderManager("./shaders/button.vert", "./shaders/button.frag");
	shaderManager textShad("./shaders/text.vert", "./shaders/text.frag");
	
	ttest->setShader(&textShad);
	ttest2->setShader(&textShad);
	ttest3->setShader(&textShad);
	
	myGui=new gui(test2);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	

	mainRender = new render(&textShad);

	button* btn;
	
	
	text testText(ttest);
	testText.setCol(color(1,0.7,0.9));
	//testText.init();
	char testStr[] = "Hello World";

	testText.bufferData(testStr);
	testText.setPos(-0.5, 0);
	mainRender->add(&testText);

	
	
	vbox* theBox = new vbox(&myGui->root);
	theBox->spacing = 0.06;
	theBox->transy = -0.25;
	for (int i = 0; i < 3; i++) {
		btn = new button(0.5, 0.05, theBox);
		btn->setCol(1, 0, 0, 0);
		btn->num = i;
		theBox->add(btn);
	}
	myGui->root.add(theBox);

	myGui->root.updateAll();

	char time[128];

	while (isRunning){
		sprintf_s(time, "SDL TIME %c %.3f", (SDL_GetTicks() / 500) % 128, SDL_GetTicks()/1000.f);
		testText.bufferData(time);

		//testText.setRot(2*3.141592*(SDL_GetTicks() / 30000.f));
		testText.setCol(color(fmod(SDL_GetTicks() / 5000.f,1), fmod(SDL_GetTicks() / 3000.f,1), fmod(SDL_GetTicks() / 2000.f,1)));
		myGui->root.updateAll();

		switch ((SDL_GetTicks()/3000)%3)
		{
		case 0:
			testText.myAtlas = ttest;
			break;
		case 1:
			testText.myAtlas = ttest2;
			break;
		case 2:
			testText.myAtlas = ttest3;
			break;
		default:
			break;
		}
		
		glClearColor(0,0,0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		
		//myGui->guiRender.drawAll();
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
		myGui->root.checkEvent(&events);

		if (events.type == SDL_QUIT) {
			isRunning = false;
		}
	};
}
