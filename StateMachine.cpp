#include "StateMachine.h"

void StateMachine::push(GameState *pState)
{
	states.push_back(pState);
	states.back()->enter();
}
void StateMachine::pop()
{
	if(!states.empty())
		if(states.back()->exit()) {
			delete states.back();
			states.pop_back();
		}
}
void StateMachine::change(GameState *pState)
{
	if(!states.empty()) {
		if(states.back()->getState() == pState->getState())
			return;
		if(states.back()->exit())	{
			delete states.back();
		states.pop_back();
		}
	}
	states.push_back(pState);
	states.back()->enter();
}
void StateMachine::update()
{
	if(!states.empty())
		states.back()->update();
}
void StateMachine::render()
{
	if(!states.empty())
		states.back()->render();
}