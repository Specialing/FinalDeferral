#ifndef __MENU__
#define __MENU__

#include "GameState.h"
#include "MenuButton.h"

class Menu : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool enter();
	virtual bool exit();

	virtual std::string getState() const { return menuID; }

protected:
	std::vector<GameObject*>gObjects;
private:
	static const std::string menuID;
	static void toPlay();
	static void exitMenu();
};
#endif