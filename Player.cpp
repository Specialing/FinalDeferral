#include "Player.h"

void Player::draw()
{
	SDLGameObject::draw();
}
void Player::update()
{
	input();
	SDLGameObject::update();		
}
void Player::clean()
{
}
void Player::input()
{
	/*if(TheInputHandler::Instance()->joyInit()) {
		if(TheInputHandler::Instance()->xval(0,1) > 0 || TheInputHandler::Instance()->xval(0,1) < 0)
			vel.setX(1 * TheInputHandler::Instance()->xval(0,1));
		if(TheInputHandler::Instance()->yval(0,1) > 0 || TheInputHandler::Instance()->yval(0,1) < 0)
			vel.setY(1 * TheInputHandler::Instance()->yval(0,1));
		if(TheInputHandler::Instance()->xval(0,2) > 0 || TheInputHandler::Instance()->xval(0,2) < 0)
			vel.setX(1 * TheInputHandler::Instance()->xval(0,2));
		if(TheInputHandler::Instance()->yval(0,2) > 0 || TheInputHandler::Instance()->yval(0,2) < 0)
			vel.setY(1 * TheInputHandler::Instance()->yval(0,2));
	}
	if(TheInputHandler::Instance()->getButtons(0,0))
		vel.setX(1);
	if(TheInputHandler::Instance()->getState(LEFT))
		vel.setX(1);
	Vector* vec = TheInputHandler::Instance()->getPos();
	vel = (*vec - mPos)/100;*/
	Vector* loc = TheInputHandler::Instance()->getPos();
	vel = (*loc - pos);
	vel /= 50;

	/*TheInputHandler::Instance()->update();
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
		vel.setY(1);*/
}