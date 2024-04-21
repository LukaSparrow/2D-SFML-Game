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

	this->createHitboxComponent(this->sprite, 108.f, 32.f, 48.f, 96.f);
	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);


	// Adjust to player_sheet
	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 7, 0, 256, 128);
	this->animationComponent->addAnimation("RUN", 10.f, 0, 1, 7, 1, 256, 128);
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
		this->animationComponent->play("IDLE", dt);
	}
	else if(this->movementComponent->getState(MOVING_RIGHT))
	{
		this->sprite.setOrigin(0.f, 0.f);
		this->sprite.setScale(1.f, 1.f);
		this->animationComponent->play("RUN", dt);
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->sprite.setOrigin(264.f, 0.f);
		this->sprite.setScale(-1.f, 1.f);
		this->animationComponent->play("RUN", dt);
	}
	else if (this->movementComponent->getState(MOVING_UP))
	{
		this->animationComponent->play("RUN", dt);
	}
	else if (this->movementComponent->getState(MOVING_DOWN))
	{
		this->animationComponent->play("RUN", dt);
	}


	this->hitboxComponent->update();
}
