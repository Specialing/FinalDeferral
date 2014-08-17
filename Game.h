#ifndef __GAME__
#define __GAME__

#include "Player.h"
#include "Enemy.h"
#include "Vector.h"
#include "StateMachine.h"

#include <iostream>


class Game
{
public:
	Game(){};
	~Game(){};

	bool init(const char* title, int x, int y, int w, int h, int flags);
	void render();
	void update();
	void hEvents();
	void clean();

	bool running() { return gRun; }

	SDL_Renderer* getRenderer() const { return gRenderer; }

	static Game* Instance() {
		if(s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	bool isPressed(SDL_Keycode k) { return keys[k]; }
	
	StateMachine* state;
	StateMachine* getState() { return state; }

private:
	static Game* s_pInstance;
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;


	int frame;
	bool gRun;
	int curState;

protected:
	std::vector<GameObject*> gObjects;
	std::map<int, bool> keys;

};
typedef Game TheGame;
#endif /* Defined (__GAME__) */