#include "box.h"



void box::draw()
{
	shader->use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

box::box(float x1, float y1, float x2, float y2,shaderManager *myShader)
{
	shader = myShader;
	vertices[0] = x1;
	vertices[1] = y1;
	vertices[2] = 0;
	vertices[3] = x1;
	vertices[4] = y2;
	vertices[5] = 0;
	vertices[6] = x2;
	vertices[7] = y2;
	vertices[8] = 0;
	vertices[9] = x2;
	vertices[10] = y1;
	vertices[11] = 0;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


box::~box()
{
}