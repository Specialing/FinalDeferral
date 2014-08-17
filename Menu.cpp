#include "Menu.h"
#include "Game.h"

const std::string Menu::menuID = "MENU";

void Menu::update()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++)
		gObjects[i]->update();
}

void Menu::render()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++)
		gObjects[i]->draw();
}

bool Menu::enter()
{
	TheTextureManager::Instance()->load("assets/enter.png", "Play", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("assets/exit.png", "Exit", TheGame::Instance()->getRenderer());
	
	GameObject* b1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "Play"),toPlay);
	GameObject* b2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "Exit"),exitMenu);

	gObjects.push_back(b1);
	gObjects.push_back(b2);
	
	std::cout<<"Entering Menu"<<std::endl;
	return true;
}
bool Menu::exit()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++)
		gObjects[i]->clean();

	gObjects.clear();
	TheTextureManager::Instance()->clearMap("Play");
	TheTextureManager::Instance()->clearMap("Exit");

	std::cout<<"Exiting Menu"<<std::endl;
	return true;
}
void Menu::toPlay()
{
	TheGame::Instance()->getState()->change(new Play());
	std::cout<<"Play button"<<std::endl;
}
void Menu::exitMenu()
{
	SDL_Quit();
	std::cout<<"Exit button"<<std::endl;
}
