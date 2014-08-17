#ifndef __PAUSESTATE__
#define __PAUSESTATE__

#include "GameState.h"

class Pause : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool enter();
	virtual bool exit();

	virtual std::string getState() const { return pauseID; }

private:
	static void toMain();
	static void resume();

	static const std::string pauseID;

	std::vector<GameObject*>gObjects;
};
#endif