#version 330 core
out vec4 FragColor;
  
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  
in vec2 texCoord;

uniform sampler2D text;

void main()
{
	
    FragColor = vertexColor*vec4(1,1,1, texture(text, texCoord).r);//vec4(0,texCoord.x,texCoord.y,0.5+ texture(text, texCoord).r);
}