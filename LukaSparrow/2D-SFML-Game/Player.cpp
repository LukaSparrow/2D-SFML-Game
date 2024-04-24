#include"stdafx.h"
#include"Player.h"

// Initializers
void Player::initVariables()
{
	this->attacking = false;
}

void Player::initComponents()
{
	
}

// Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 108.f, 36.f, 48.f, 92.f);
	this->createMovementComponent(350.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	// Adjust to player_sheet
	this->animationComponent->addAnimation("IDLE", 11.f, 0, 0, 7, 0, 256, 128);
	this->animationComponent->addAnimation("RUN", 6.f, 0, 1, 7, 1, 256, 128);
	this->animationComponent->addAnimation("ATTACK", 6.f, 0, 2, 19, 2, 256, 128);
}

Player::~Player()
{
}

// Functions
void Player::updateAttack()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->attacking = true;
	}
}

void Player::updateAnimation(const float& dt)
{
	if (this->attacking)
	{
		// Animate and check for animation end
		if (this->animationComponent->play("ATTACK", dt, true))
		{
			this->attacking = false;
		}
	}
	if (this->movementComponent->getState(IDLE))
	{
		this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		if (this->sprite.getScale().x < 0.f)
		{
			this->sprite.setOrigin(0.f, 0.f);
			this->sprite.setScale(1.f, 1.f);
		}
		this->animationComponent->play("RUN", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		if (this->sprite.getScale().x > 0.f)
		{
			this->sprite.setOrigin(264.f, 0.f);
			this->sprite.setScale(-1.f, 1.f);
		}
		this->animationComponent->play("RUN", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_UP))
	{
		this->animationComponent->play("RUN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_DOWN))
	{
		this->animationComponent->play("RUN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}

}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);
	
	this->updateAttack();
	
	this->updateAnimation(dt);

	this->hitboxComponent->update();
}
