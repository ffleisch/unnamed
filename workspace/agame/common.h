#pragma once
#ifndef COMMON_INC
#define COMMON_INC
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <math.h>
#include <list>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

struct color {
	float r;
	float g;
	float b;
	float a;
	color(float red, float green, float blue) :r(red), g(green), b(blue), a(1) {};
	color(float red, float green, float blue, float alpha) :r(red), g(green), b(blue), a(alpha) {};
	color(float brigh) :r(brigh), g(brigh), b(brigh), a(1) {};
	color():r(1),g(0),b(1),a(1) {};
};

#endif // !COMMON_INC
 