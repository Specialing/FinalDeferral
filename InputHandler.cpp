#include "InputHandler.h"

const int deadZone = 10000;
InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{
	keys = SDL_GetKeyboardState(NULL);

	for(int i = 0; i < 3; i++)
		mouse.push_back(false);
}

/*void InputHandler::initJoy()
{
	/*if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	if(SDL_NumJoysticks() > 0) {
		for(int i=0; i<SDL_NumJoysticks(); i++) {
			SDL_Joystick* joy = SDL_JoystickOpen(i);

			if(joy) {
				joysticks.push_back(joy);
				jsValues.push_back(std::make_pair(new Vector(0,0),new Vector(0,0)));

				std::vector<bool> temp;

				for(int j = 0; j < SDL_JoystickNumButtons(joy); j++)
					temp.push_back(false);

				buttons.push_back(temp);
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		jInit = true;
	}	
	else
		jInit = false;
}*/
void InputHandler::clean()
{
	/*if(jInit)
		for(int i = 0; i<SDL_NumJoysticks(); i++)
			SDL_JoystickClose(joysticks[i]);*/
}
bool InputHandler::isKeyDown(SDL_Scancode key)
{
		if(keys[key] == 1)
			return true;
		return false;
}
bool InputHandler::isKeyUp(SDL_Scancode key)
{
	if(keys[key] != 1)
		return true;
	return false;

}
void InputHandler::update()
{
	SDL_Event event;

	while(SDL_PollEvent(&event)) 
	{
		switch(event.type)
		{
		case SDL_QUIT:
			SDL_Quit();
			break;
		case SDL_KEYDOWN:
			isKeyDown(event.key.keysym.scancode);
			break;
		default:
			break;
		}
	}
}
		/*if(event.type == SDL_JOYAXISMOTION) 
		{
			int which = event.jaxis.which;
			//Left stick
			//l or r
			if(event.jaxis.axis == 0)
			{
				if(event.jaxis.value > deadZone) 
				{
					jsValues[which].first->setX(1);
				}
				else if(event.jaxis.value < -deadZone) 
				{
					jsValues[which].first->setX(-1);
				} 
				else
				{
					jsValues[which].first->setX(0);
				}
			}
			//U or d
			if(event.jaxis.axis == 1) 
			{
				if(event.jaxis.value > deadZone)
				{
					jsValues[which].first->setY(1);
				}
				else if(event.jaxis.value < -deadZone)
				{
					jsValues[which].first->setY(-1);
				}
				else 
				{
					jsValues[which].first->setY(0);
				}
			}
			//Right Stick
			//l or r
			if(event.jaxis.axis == 3) 
			{
				if(event.jaxis.value > deadZone)
				{
					jsValues[which].second->setX(1);
				}
				else if(event.jaxis.value < - deadZone)
				{
					jsValues[which].second->setX(-1);
				}
				else
				{
					jsValues[which].second->setX(0);
				}
			}
			//u or d
			if(event.jaxis.axis == 4) 
			{
				if(event.jaxis.value > deadZone)
				{
					jsValues[which].second->setY(1);
				}
				else if(event.jaxis.value < - deadZone)
				{
					jsValues[which].second->setY(-1);
				}
				else
				{
					jsValues[which].second->setY(0);
				}
			}
			if(event.type == SDL_JOYBUTTONDOWN)
			{
				int which = event.jaxis.which;
				buttons[which][event.jbutton.button] = true;
			}
			if(event.type == SDL_JOYBUTTONUP)
			{
				int which = event.jaxis.which;
				buttons[which][event.jbutton.button] = false;
			}
		}*/
		/*if(event.type == SDL_MOUSEBUTTONDOWN) {
			if(event.button.button == SDL_BUTTON_LEFT)
				mouse[LEFT] = true;
			if(event.button.button == SDL_BUTTON_MIDDLE)
				mouse[MID] = true;
			if(event.button.button == SDL_BUTTON_RIGHT)
				mouse[RIGHT] = true;
		}
		if(event.type == SDL_MOUSEBUTTONUP) {
			if(event.button.button == SDL_BUTTON_LEFT)
				mouse[LEFT] = false;
			if(event.button.button == SDL_BUTTON_MIDDLE)
				mouse[MID] = false;
			if(event.button.button == SDL_BUTTON_RIGHT)
				mouse[RIGHT] = false;
		}
		if(event.type == SDL_MOUSEMOTION)
		{
			mPos->setX(1);
			mPos->setY(1);			
		}
	}*/

bool InputHandler::getState(int buttonNo)
{
	return mouse[buttonNo];
}
/*int InputHandler::xval(int joy, int stick)
{
	if(jsValues.size() > 0) {
		if(stick == 1)
			return jsValues[joy].first->getX();
		else if(stick == 2)
			return jsValues[joy].second->getX();
	}
	return 0;
}
int InputHandler::yval(int joy, int stick)
{
	if(jsValues.size() > 0) {
		if(stick == 1)
			return jsValues[joy].first->getY();
		else if(stick == 2)
			return jsValues[joy].second->getY();
	}
	return 0;
}*/

/*bool InputHandler::isKeyUp(SDL_Scancode key)
{
	if(keys*/
