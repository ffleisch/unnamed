#include "button.h"

button::button(float w, float h, guiNode * par):img(0,0,w,h),guiNode(par)
{
	color(.5, 0.5, 0.8);
	guiRender->add(&img);
	width = w;
	height = h;
}

void button::updateAll() {
	guiNode::updateAll();
	img.setPos(posx, posy);
}

void button::checkEvent(SDL_Event* e) {
	
	guiNode::checkEvent(e);

	if (e->type == SDL_MOUSEBUTTONDOWN) {
		if (e->button.button == SDL_BUTTON_LEFT) {
			if (isInside(e->button.x,e->button.y)) {
				isPressed = true;
				normCol = color(0.2, (float)rand()/RAND_MAX, 0.3);
				//delete(parent);
				if (onClick != NULL) {
					onClick();
				}
			}
		}

	}
	if (e->type == SDL_MOUSEBUTTONUP) {
		if (e->button.button == SDL_BUTTON_LEFT) {
			if (isInside(e->button.x, e->button.y)) {
				
			}
		}
		isPressed = false;
	}

	if (e->type == SDL_MOUSEMOTION ||e->type==SDL_MOUSEBUTTONDOWN||e->type==SDL_MOUSEBUTTONUP) {
		if (isInside(e->motion.x, e->motion.y)) {
			if (isPressed) {
				img.setCol(pressCol);
			}else{
				img.setCol(hoverCol);
			}
		}
		else {
			isPressed = false;
			img.setCol(normCol);
		}
	}
	

}

bool button::isInside(float x, float y)
{
	if (abs(x-posx)<width/2) {
		if (abs(y - posy) < height / 2) {
			return(true);
		}
	}
	return(false);
}
bool button::isInside(int x, int y)
{
	return(isInside(toGLCordX(x), toGLCordY(y)));
}

void button::setCol(float r, float g, float b, float a)
{
	img.setCol(r,g,b,a);
}

button::~button()
{
	guiRender->rem(&img);
}
