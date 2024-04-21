#include "Player.h"

// Initializers
void Player::initVariables()
{

}

void Player::initComponents()
{
	
}

// Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	// Adjust to player_sheet
	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 0, 7, 0, 256, 128);
	this->animationComponent->addAnimation("RUN_RIGHT", 10.f, 0, 1, 7, 1, 256, 128);
}

Player::~Player()
{
}

// Functions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);
	
	if (this->movementComponent->getState(IDLE))
	{
		this->animationComponent->play("IDLE_RIGHT", dt);
	}
	else if(this->movementComponent->getState(MOVING_RIGHT))
	{
		this->animationComponent->play("RUN_RIGHT", dt);
	}
}
