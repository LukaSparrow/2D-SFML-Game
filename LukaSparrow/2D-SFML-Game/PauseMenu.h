#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

#include"Button.h"

class PauseMenu
{
private:
	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, Button*> buttons;

protected:

public:
	PauseMenu(sf::RenderWindow& window);
	virtual ~PauseMenu();

	// Functions
	void update();
	void render(sf::RenderTarget& target);
};