#pragma once
#include "Entity.h"

class Entity;

class Player : public Entity
{
private:
	// Variables;
	bool attacking;
	sf::Sprite weapon_sprite;
	sf::Texture weapon_texture;

	// Initializers
	void initVariables();
	void initComponents();

public:
	Player(float x, float y, sf::Texture& texture);
	virtual ~Player();

	// Accessors
	AttributeComponent* getAttributeComponent();

	// Functions
	void loseHP(const int hp);
	void gainHP(const int hp);
	void loseEXP(const int exp);
	void gainEXP(const int exp);
	void updateAttack();
	void updateAnimation(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget& target, sf::Shader* shader = nullptr, const bool show_hitbox = false);
};