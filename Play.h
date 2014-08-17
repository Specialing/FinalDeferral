#ifndef __PLAY__
#define __PLAY__

#include "GameState.h"
#include "SDLGameObject.h"

class Play : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool enter();
	virtual bool exit();

	virtual std::string getState() const { return playID; }

	bool collision(SDLGameObject* p1, SDLGameObject* p2);
private:
	static const std::string playID; 
	std::vector<GameObject*> gObjects;
};
#endif