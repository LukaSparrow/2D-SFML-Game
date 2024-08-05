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

	this->createHitboxComponent(this->sprite, 12.f, 10.f, 40.f, 54.f);
	this->createMovementComponent(200.f, 1600.f, 1000.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1);

	// Adjust to player_sheet
	this->animationComponent->addAnimation("IDLE", 15.f, 0, 0, 8, 0, 64, 64);
	this->animationComponent->addAnimation("WALK_DOWN", 11.f, 0, 1, 3, 1, 64, 64);
	this->animationComponent->addAnimation("WALK_LEFT", 11.f, 4, 1, 7, 1, 64, 64);
	this->animationComponent->addAnimation("WALK_UP", 11.f, 12, 1, 15, 1, 64, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 11.f, 8, 1, 11, 1, 64, 64);
	this->animationComponent->addAnimation("ATTACK", 6.f, 0, 2, 19, 2, 64, 64);

	if (!this->weapon_texture.loadFromFile("Resources/Images/Sprites/Player/kunai2.png"))
	{
		std::cout << "ERROR::PLAYER::COULD NOT LOAD FROM FILE." << std::endl;
	}
	this->weapon_sprite.setTexture(this->weapon_texture);
}

Player::~Player()
{
}

AttributeComponent* Player::getAttributeComponent()
{
	return this->attributeComponent;
}

void Player::loseHP(const int hp)
{
	this->attributeComponent->hp -= hp;
	if (this->attributeComponent->hp < 0)
		this->attributeComponent->hp = 0;
}

void Player::gainHP(const int hp)
{
	this->attributeComponent->hp += hp;
	if (this->attributeComponent->hp > this->attributeComponent->hpMax)
		this->attributeComponent->hp = this->attributeComponent->hpMax;
}

void Player::loseEXP(const int exp)
{
	this->attributeComponent->exp -= exp;
	if (this->attributeComponent->exp < 0)
		this->attributeComponent->exp = 0;
}

void Player::gainEXP(const int exp)
{
	this->attributeComponent->gainExp(exp);
}

// Functions
void Player::updateAttack()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		//this->attacking = true;
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
		this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{
		this->animationComponent->play("WALK_LEFT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_UP))
	{
		this->animationComponent->play("WALK_UP", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_DOWN))
	{
		this->animationComponent->play("WALK_DOWN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}

}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);
	
	this->updateAttack();
	
	this->updateAnimation(dt);

	this->hitboxComponent->update();

	this->weapon_sprite.setPosition(this->getCenter());
}

void Player::render(sf::RenderTarget& target, sf::Shader* shader, const bool show_hitbox)
{
	if(shader)
	{
		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", this->getCenter());

		target.draw(this->sprite, shader);

		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", this->getCenter());
		target.draw(this->weapon_sprite, shader);
	}
	else
	{
		target.draw(this->sprite);
		target.draw(this->weapon_sprite);
	}

	if(show_hitbox)
		this->hitboxComponent->render(target);
}
