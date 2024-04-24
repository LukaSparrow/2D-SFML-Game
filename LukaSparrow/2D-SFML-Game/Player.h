#pragma once
#include "Entity.h"

class Entity;

class Player : public Entity
{
private:
	// Variables;
	bool attacking;

	// Initializers
	void initVariables();
	void initComponents();

public:
	Player(float x, float y, sf::Texture& texture);
	virtual ~Player();

	// Functions
	void updateAttack();
	void updateAnimation(const float& dt);
	virtual void update(const float& dt);
};