#include "Play.h"
#include "Game.h"

const std::string Play::playID = "PLAY";

void Play::update()
{
	if(!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_P))
		TheGame::Instance()->getState()->push(new Pause());

	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++) {
		gObjects[i]->update();
	}
	if(collision(dynamic_cast<SDLGameObject*>(gObjects[0]),dynamic_cast<SDLGameObject*>(gObjects[1])))
		TheGame::Instance()->getState()->push(new GameOver());
}
void Play::render()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++) {
		gObjects[i]->draw();
	}
}
bool Play::enter()
{
	TheTextureManager::Instance()->load("assets/PlayerDestroyed.png", "Player", TheGame::Instance()->getRenderer());
	GameObject* player = new Player(new LoaderParams(100, 100, 32, 30, "Player"));
	TheTextureManager::Instance()->load("assets/PShipFire.png", "Enemy", TheGame::Instance()->getRenderer());
	GameObject* enemy = new Enemy(new LoaderParams(500, 200, 32, 30, "Enemy"));
	gObjects.push_back(player);
	gObjects.push_back(enemy);

	std::cout<<"Entering Play"<<std::endl;
	return true;
}
bool Play::exit()
{
	for(std::vector<GameObject*>::size_type i = 0; i < gObjects.size(); i++) {
		gObjects[i]->clean();
	}
	gObjects.clear();

	TheTextureManager::Instance()->clearMap("Player");

	std::cout<<"Exiting Play"<<std::endl;
	return true;
}
bool Play::collision(SDLGameObject* p1, SDLGameObject* p2)
{
	int lP1, rP1, tP1, bP1;
	int lP2, rP2, tP2, bP2;

	//Player rectangle
	lP1 = p1->getPos().getX();
	rP1 = lP1 + p1->getW();
	tP1 = p1->getPos().getY();
	bP1 = tP1 + p1->getH();

	//Enemy rectangle
	lP2	= p2->getPos().getX();
	rP2 = lP2 + p2->getW();
	tP2 = p2->getPos().getY();
	bP2 = tP2 + p2->getH();

	if(bP1 <= tP2)
		return false;
	if(tP1 >= bP2)
		return false;
	if(lP1 >= rP2)
		return false;
	if(rP1 <= lP2)
		return false;

	return true;
}