#pragma once

#include"State.h"
#include"PauseMenu.h"
#include"TileMap.h"

class State;
class PauseMenu;
class TileMap;

class GameState : public State
{
private:
	sf::Font font;
	PauseMenu* pmenu;

	Player* player;
	sf::Texture texture;

	TileMap map;

	// Functions
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initPauseMenu();
	void initPlayers();

public:
	GameState(StateData* state_data);
	virtual ~GameState();

	// Functions
	void updatePauseMenuButtons();
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

