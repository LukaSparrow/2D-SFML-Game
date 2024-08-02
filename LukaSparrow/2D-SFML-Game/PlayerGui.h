#pragma once

#include"Player.h"

class Player;
class sf::RectangleShape;

class PlayerGui
{
private:
	Player* player;

	sf::Font font;

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
	void initHPBar();
	void initEXPBar();

public:
	// Constructors and Destructors
	PlayerGui(Player* player);
	virtual ~PlayerGui();

	// Functions
	void updateHPBar();
	void updateEXPBar();
	void update(const float& dt);

	void renderHPBar(sf::RenderTarget& target);
	void renderEXPBar(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};