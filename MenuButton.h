#ifndef __MENUBUTTON__
#define __MENUBUTTON__

#include "SDLGameObject.h"
#include "InputHandler.h"

class MenuButton : public SDLGameObject
{
public:
	MenuButton(const LoaderParams* pParams, void (*back)());

	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	enum buttonState
	{
		OUT = 0,
		OVER = 1,
		CLICK = 2
	};
	void (*call)();
	bool release;
	
};
#endif