#pragma once

#include"Player.h"
#include"Gui.h"

class Player;
class Gui;
class sf::RectangleShape;

class PlayerGui
{
private:
	Player* player;

	sf::VideoMode& vm;
	sf::Font font;

	// LVL Display
	std::string levelDisplayString;
	sf::Text levelDisplayText;
	sf::RectangleShape levelDisplayBack;


	// EXP Bar
	std::string expBarString;
	sf::Text expBarText;
	float expBarMaxWidth;
	sf::RectangleShape expBarBack;
	sf::RectangleShape expBarInner;

	// HP Bar
	std::string hpBarString;
	sf::Text hpBarText;
	float hpBarMaxWidth;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInner;

	void initFont();
	void initLevelDisplay();
	void initEXPBar();
	void initHPBar();

public:
	// Constructors and Destructors
	PlayerGui(Player* player, sf::VideoMode& vm);
	virtual ~PlayerGui();

	// Functions
	void updateLevelDisplay();
	void updateHPBar();
	void updateEXPBar();
	void update(const float& dt);

	void renderLevelDisplay(sf::RenderTarget& target);
	void renderHPBar(sf::RenderTarget& target);
	void renderEXPBar(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};