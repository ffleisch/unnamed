#version 330 core

layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 3) in vec2 texCoordIn;

out vec2 texCoord;

uniform vec4 col;
uniform mat4 transform;
uniform mat4 projection;

out vec4 vertexColor; // specify a color output to the fragment shader

void main(){
    gl_Position =transform*projection*vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertexColor = col;
	texCoord=texCoordIn;//(transform*projection*vec4(aPos, 1.0)).xy;
}