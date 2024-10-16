#pragma once

#include"MainMenuState.h"

class MainMenuState;

class Game
{
private:

	// Variables
	GraphicsSettings gfxSettings;
	StateData stateData;
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	float gridSize;

	// Initialization
	void initVariables();
	void initGraphicsSettings();
	void initWindow();
	void initKeys();
	void initStateData();
	void initStates();

public:
	// Constructors / Destructors
	Game();
	virtual ~Game();

	// Functions
	
	// Other
	void endApplication();

	// Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	// Render
	void render();

	// Core
	void run();
};