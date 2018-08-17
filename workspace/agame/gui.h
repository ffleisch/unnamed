#pragma once
#ifndef GUI_INC
#define GUI_INC


class gui
{
public:
	virtual void render()=0;

	gui();
	~gui();
};

#endif // !GUI_INC