#include "text.h"



void text::init()
{
	transf = glm::mat4(1.0);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, myAtlas->textureID);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*elemNum, data, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indNum, ind, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(3);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}



void text::bufferData(char* text)
{
	shader = myAtlas->textShader;
	

	elemNum = 0;
	indNum = 0;
	cnum = 0;
	float xoff = 0;
	float yoff = 0;
	for (char* c = text; *c != 0; c++) {
		
		character* myCh=&myAtlas->myChars[*c];
		
		float y =yoff+ myCh->bearing.y-myCh->size.y;
		float x =xoff+ myCh->bearing.x;
		float w = myCh->size.x;
		float h = myCh->size.y;

		float texxoff = (float)myCh->atPos.x / myAtlas->atW;
		float texyoff = (float)myCh->atPos.y / myAtlas->atH;
		float wf = w / myAtlas->atW;
		float hf = h / myAtlas->atH;

		xoff += myCh->advance.x>>6;
		yoff += myCh->advance.y >> 6;
		int off = cnum * 20;

		data[off] = x;
		data[off + 1] = y+h;
		data[off + 2] = 0.f;
		data[off + 3] = texxoff;
		data[off + 4] = texyoff;
	
		data[off + 5] = x+w;
		data[off + 5 + 1] = y + h;
		data[off + 5 + 2] = 0.f;
		data[off + 5 + 3] = texxoff +wf;
		data[off + 5 + 4] = texyoff;

		data[off + 10] = x+w;
		data[off + 10 + 1] = y;
		data[off + 10 + 2] = 0.f;
		data[off + 10 + 3] = texxoff +wf;
		data[off + 10 + 4] = texyoff +hf;

		data[off + 15] = x;
		data[off + 15 + 1] = y;
		data[off + 15 + 2] = 0.f;
		data[off + 15 + 3] = texxoff;
		data[off + 15 + 4] = texyoff +hf;
		
		ind[indNum]=0+cnum*4;
		ind[indNum+1]=1+cnum * 4;
		ind[indNum+2]=3+cnum * 4;
		ind[indNum+3]=1+cnum * 4;
		ind[indNum+4]=2+cnum * 4;
		ind[indNum+5]=3+cnum * 4;
		
		cnum++;
		elemNum += 20;
		indNum += 6;
		
		if (((cnum+1)*20)>dataLen) {
			float* old = data;
			float* newArr= new float[2*dataLen];
			memcpy(newArr,data,dataLen*sizeof(float));
			data = newArr;
			//delete [] old;
			dataLen *= 2;

		}

		if (indNum+6 > indLen) {
			GLuint* old = ind;
			GLuint* newArr = new GLuint[2 * indLen];
			memcpy(newArr, ind, indLen * sizeof(GLuint));
			ind = newArr;
			//delete [] old;
			indLen *= 2;
		}
	}

	/*//test
	float x1 = 0.5;
	float y1 = 0.5;
	float x2 = 1;
	float y2 = 1;
	data[0] = x1;
	data[1] = y1;
	data[2] = 0;
	data[3] = x1;
	data[4] = y2;
	data[5] = 0;
	data[6] = x2;
	data[7] = y2;
	data[8] = 0;
	data[9] = x2;
	data[10] = y1;
	data[11] = 0;
	*/

	glBindVertexArray(VAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, myAtlas->textureID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*elemNum, data,GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indNum, ind, GL_STATIC_DRAW);
	//std::cout << std::hex << glGetError() << std::endl;

	glBindVertexArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void text::setCol(color col)
{
	this->col = col;
}
void text::updatePos()
{
	transf = glm::mat4(1.0);
	transf = glm::translate(transf, glm::vec3(posx, posy, 0.f));

	transf = glm::rotate(transf, rotation, glm::vec3(0, 0, 1));
}

void text::setPos(float px, float py)
{
	posx = px;
	posy = py;
	updatePos();
}

void text::setRot(float rot)
{
	rotation = rot;
	updatePos();
}

void text::setPosRot(float px, float py, float rot)
{
	posx = px;
	posy = py;
	rotation = rot;
	updatePos();
}

void text::setShaderUni()
{
	myAtlas->projection=glm::ortho(-512.f,512.f,-512.f,512.f);
	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(transf));
	glUniformMatrix4fv(glGetUniformLocation(shader->ID, "projection"), 1, GL_FALSE, glm::value_ptr(myAtlas->projection));
	glUniform4f(glGetUniformLocation(shader->ID, "col"), col.r, col.g, col.b, col.a);
}

void text::draw() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//std::cout << glGetError() << std::endl;

	shader->use();
	setShaderUni();
	glBindVertexArray(VAO);
	glBindTexture(GL_TEXTURE_2D,myAtlas->textureID);
	glDrawElements(GL_TRIANGLES, indNum, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

text::text(textHelper* source):col(0.5)
{
	myAtlas = source;
	shader = myAtlas->textShader;
	init();
}


text::~text()
{
}
