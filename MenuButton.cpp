#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* pParams, void (*back)()) : SDLGameObject(pParams), call(back)
{
	cFrame = OUT;
}
void MenuButton::draw()
{
	SDLGameObject::draw();
}
void MenuButton::update()
{
	Vector* gPos = TheInputHandler::Instance()->getPos();

	if((gPos->getX() < (pos.getX() + width)) && (gPos->getX() > pos.getX()) && (gPos->getY() < (pos.getY() + height)) && (gPos->getY() > pos.getY())) 
	{
		if(TheInputHandler::Instance()->getState(LEFT) && release) 
		{
			cFrame = CLICK;
			call();
			release = false;
		} else if(!TheInputHandler::Instance()->getState(LEFT))		{
			release = true;
			cFrame = OVER;
		}	else	{
			cFrame = OUT;
		}
	}
}
void MenuButton::clean()
{
	SDLGameObject::clean();
}