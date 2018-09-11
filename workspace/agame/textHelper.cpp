#include "textHelper.h"



void textHelper::setShader(shaderManager * man)
{
	textShader = man;
}

textHelper::textHelper(const char * path, int* w, int* h):textHelper(path, w,h,48)
{
}

textHelper::textHelper(const char* path, int* w, int* h,int height)
{
	FT_Face face;
	atW = 0;
	atH = 0;
	if (!isInit) {
		if (FT_Init_FreeType(&ftLib)) {
			throwError("Could not init Freetype");
		}
		isInit = true;
	}

	if (FT_New_Face(ftLib, path, 0, &face)) {
		throwError("Could not create face");
	}
	FT_Set_Pixel_Sizes(face, 0, height);

	projection = glm::ortho(0, *w, 0, *h);

	for (GLubyte c = 0; c < 128; c++) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			continue;
		};
		atW += face->glyph->bitmap.width;
		atH = std::max(atH,face->glyph->bitmap.rows);
	}
	//std::cout << std::hex << glGetError() << std::endl;

	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1,&textureID);
	//std::cout << std::hex << glGetError() << " gen texture " << std::endl;

	glBindTexture(GL_TEXTURE_2D, textureID);
	//std::cout << std::hex << glGetError() << " bind texture " << std::endl;

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, atW, atH, 0, GL_RED, GL_UNSIGNED_BYTE, 0);
	
	//std::cout << std::hex << glGetError() <<" create texture "<< std::endl;

	//std::cout << std::dec<<GL_MAX_TEXTURE_SIZE << " " << atW << " " << atH << std::endl;

	//std::cout << atW << " " << atH;
	

	int xoff = 0;
	for (GLubyte c = 0; c < 128; c++) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			continue;
		};
		glTexSubImage2D(GL_TEXTURE_2D, 0, xoff,0,face->glyph->bitmap.width,face->glyph->bitmap.rows,GL_RED,GL_UNSIGNED_BYTE,face->glyph->bitmap.buffer );
		//std::cout <<std::hex<< glGetError()<<" fill texture" << std::endl;

		character* mych=&myChars[c];

		mych->size.x = face->glyph->bitmap.width;
		mych->size.y = face->glyph->bitmap.rows;

		mych->advance.x = face->glyph->advance.x;
		mych->advance.y = face->glyph->advance.y;

		mych->bearing.x = face->glyph->bitmap_left;
		mych->bearing.y = face->glyph->bitmap_top;

		mych->atPos.x = xoff;
		mych->atPos.y = 0;

		xoff += face->glyph->bitmap.width;
	}
	//std::cout << std::hex << glGetError() << std::endl;

	FT_Done_Face(face);
}


textHelper::~textHelper()
{
}
