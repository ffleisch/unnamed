#include "box.h"



void box::draw()
{
	glUniform4f(glGetUniformLocation(shader->ID, "col"), color[0], color[1], color[2], color[3]);

	shader->use();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void box::setCoords(float x1, float y1, float x2, float y2)
{
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
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void box::setCol(float red, float green, float blue, float alpha)
{
	color[0] = red;
	color[1] = green;
	color[2] = blue;
	color[3] = alpha;
}

box::box(float x1, float y1, float x2, float y2,shaderManager *myShader)
{
	shader = myShader;
	vertices[0] = x1;
	vertices[1] = y1;
	vertices[2] = 0;
	vertices[3] =  x1;
	vertices[4] =  y2;
	vertices[5] = 0;
	vertices[6] = x2;
	vertices[7] = y2;
	vertices[8] = 0;
	vertices[9] = x2;
	vertices[10] = y1;
	vertices[11] = 0;
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 3;
	indices[3] = 1;
	indices[4] = 2;
	indices[5] = 3;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


box::~box()
{

}
