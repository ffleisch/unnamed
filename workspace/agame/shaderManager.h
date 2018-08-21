#pragma once
#ifndef SHADERMANAGER_INC
#define SHADERMANAGER_INC
#include "common.h"
#include "Error.h"

class shaderManager
{
public:
	GLuint ID;

	shaderManager(const char* vertPath,const char* fragPath);
	void use();
	~shaderManager();

	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
};

#endif