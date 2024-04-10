#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	:State(window)
{

}

GameState::~GameState()
{

}

void GameState::endState()
{
	std::cout << "Ending GameState" << std::endl;
}

void GameState::updateKeyBinds(const float& dt)
{
	this->checkForQuit();
}

void GameState::update(const float& dt)
{
	this->updateKeyBinds(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A" << std::endl;
}

void GameState::render(sf::RenderTarget* target)
{

}
