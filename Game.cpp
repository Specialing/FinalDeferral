#include "Game.h"

Game* Game::s_pInstance = 0;


enum gameStates
{
	MENU = 0,
	PLAY = 1,
	PAUSE = 2,
	GAMEOVER = 3
};
bool Game::init(const char* title, int x, int y, int w, int h, int flags)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		gWindow = SDL_CreateWindow(title, x, y, w, h, flags);

		if(gWindow != 0) {
			gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

			if(gRenderer != 0) {
				SDL_SetRenderDrawColor(gRenderer, 0, 105, 132, 255);
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}

	state = new StateMachine();
	state->change(new Menu());
	curState = MENU;
	
	//TheTextureManager::Instance()->load("assets/PShipFire.png", "Fire", gRenderer);
	gObjects.push_back(new Player(new LoaderParams(100, 100, 32, 30, "Player")));
	gObjects.push_back(new Enemy(new LoaderParams(300, 300, 32, 30, "Player")));

	gRun = true;

	return true;
}
void Game::render()
{
	SDL_RenderClear(gRenderer);
	state->render();
	for(std::vector<GameObject*>::size_type i = 0; i != gObjects.size(); i++)
		gObjects[i]->draw();
	SDL_RenderPresent(gRenderer);
}
void Game::hEvents()
{
	TheInputHandler::Instance()->update();
	
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		state->change(new Play());
		curState = PLAY;
		update();
	}
	while(PLAY) {
		if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
			Player::dMove();
		if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
			Player::uMove();
		if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
			Player::rMove();
		if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
			Player::lMove();
		if (TheInputHandler::Instance()->isKeyUp(SDL_SCANCODE_S) || TheInputHandler::Instance()->isKeyUp(SDL_SCANCODE_W) || TheInputHandler::Instance()->isKeyUp(SDL_SCANCODE_A) || TheInputHandler::Instance()->isKeyUp(SDL_SCANCODE_D))
			Player::noMove();
		if(collision()) {
			state->change(new GameOver());
			curState = GAMEOVER;
		}
	}
	if(GAMEOVER)
		SDL_Quit();
}
	/*SDL_Event event;

	if(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT:
			gRun = false;
			break;
		case SDL_KEYDOWN:
			keys[event.key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			keys[event.key.keysym.sym] = false;
			break;
		default:
			break;
		}
	}*/

void Game::update()
{
	/*switch (curState)	{
	case MENU:
		Menu->update();
		break;
	case PLAY:
		pObject->update();
		eObject->update();
		break;
	case GAMEOVER:
		//enddd...
		break;
	default:
		break;
	}*/

	/*for(std::vector<GameObject*>::size_type i = 0; i != gObjects.size(); i++)
		gObjects[i]->update();*/
	state->update();
}
void Game::clean()
{
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	SDL_Quit();	
}
