#include "GameOver.h"
#include "Game.h"

const std::string GameOver::overID = "GAMEOVER";

void GameOver::update()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++)
		gObjects[i]->update();
}
void GameOver::render()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++)
		gObjects[i]->draw();
}
bool GameOver::enter()
{
	TheTextureManager::Instance()->load("assets/main.png", "Menu", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("assets/resart.png", "Restart", TheGame::Instance()->getRenderer());

	GameObject* b1 = new MenuButton(new LoaderParams(200, 200, 200, 80, "Main"), toMain);
	GameObject* b2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "Restart"), restart);

	gObjects.push_back(b1);
	gObjects.push_back(b2);

	return true;
}
bool GameOver::exit()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++)
		gObjects[i]->clean();

	gObjects.clear();
	TheTextureManager::Instance()->clearMap("Main");
	TheTextureManager::Instance()->clearMap("Restart");

	return true;
}

void GameOver::toMain()
{
	TheGame::Instance()->getState()->change(new Menu());
}
void GameOver::restart()
{
	TheGame::Instance()->getState()->change(new Play());
}
