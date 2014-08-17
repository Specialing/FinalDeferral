#ifndef __INPUTS__
#define __INPUTS__

#include "Vector.h"

#include <vector>
#include <SDL.h>

enum mButtons
{
	LEFT = 0,
	MID = 1,
	RIGHT = 2
};


class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
			return s_pInstance;
	}
	
	void update();
	void clean();

	bool getState(int buttonNo);

	Vector* getPos() { return mPos; }

	bool isKeyDown(SDL_Scancode key);
	bool isKeyUp(SDL_Scancode key);
protected:
	Vector* mPos;
private:
	InputHandler();
	~InputHandler() {}
	
	const Uint8* keys;

	std::vector<std::vector<bool>> buttons;

	std::vector<bool> mouse;
	
	static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;
#endif