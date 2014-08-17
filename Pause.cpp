#include "Pause.h"
#include "GameObject.h"
#include "Game.h"

const std::string Pause::pauseID = "PAUSE";

void Pause::toMain()
{
	TheGame::Instance()->getState()->change(new Menu());
	std::cout<<"Going to main menu"<<std::endl;
}
void Pause::resume()
{
	TheGame::Instance()->getState()->pop();
}
void Pause::update()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++)
		gObjects[i]->update();
}
void Pause::render()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++)
		gObjects[i]->draw();
}
bool Pause::enter()
{
	TheTextureManager::Instance()->load("assets/resume.png", "Resume", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("assets/menu.png", "Main", TheGame::Instance()->getRenderer());

	GameObject* b1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "Resume"), resume);
	GameObject* b2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "Main"),toMain);

	std::cout<<"Pausing"<<std::endl;

	return true;
}
bool Pause::exit()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++)
		gObjects[i]->clean();
	gObjects.clear();

	TheTextureManager::Instance()->clearMap("Resume");
	TheTextureManager::Instance()->clearMap("Main");

	return true;
}