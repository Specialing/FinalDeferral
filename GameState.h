#ifndef __STATE__
#define __STATE__

#include "GameObject.h"

class GameState
{
public:
	GameState(){}
	~GameState(){}
	virtual void update()=0;
	virtual void render()=0;

	virtual bool enter()=0;
	virtual bool exit()=0;

	virtual std::string getState() const = 0;
};
#endif