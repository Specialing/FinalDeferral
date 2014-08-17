#ifndef __GAMEOVER__
#define __GAMEOVER__

#include "GameState.h"

class GameOver : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool enter();
	virtual bool exit();

	virtual std::string getState() const { return overID; }

private:
	static void toMain();
	static void restart();

	static const std::string overID;

	std::vector<GameObject*> gObjects;
};
#endif