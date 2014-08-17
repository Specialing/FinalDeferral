#ifndef __GAMESTATEMACHINE__
#define __GAMESTATEMACHINE__

#include "Menu.h"
#include "Play.h"
#include "Pause.h"
#include "GameOver.h"

class StateMachine
{
public:
	StateMachine(){}
	~StateMachine(){}

	void push(GameState* pState);
	void change(GameState* pState);
	void pop();

	void update();
	void render();

	std::vector<GameState*> states;
};
#endif