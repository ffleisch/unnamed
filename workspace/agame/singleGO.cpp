#include "singleGO.h"


//buffer erzeugen
void singleGO::init()
{
	transf = glm::mat4(1.0);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*elemNum, data, mode);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indNum, ind, mode);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}


//daten in *data an graka senden
void singleGO::bufferData()
{ 
	glBindVertexArray(VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferSubData(GL_ARRAY_BUFFER,0, sizeof(float)*elemNum, data);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER,0, sizeof(GLuint)*indNum, ind);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}


//zeichnen
void singleGO::draw() {
	shader->use();
	setShaderUni();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indNum, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

singleGO::singleGO()
{
}

singleGO::singleGO(GLuint drawMode)
{
	mode = drawMode;
}


singleGO::~singleGO()
{
}
