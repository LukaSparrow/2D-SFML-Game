#include "stdafx.h"
#include "PlayerGui.h"

// Initializers
void PlayerGui::initFont()
{
	this->font.loadFromFile("Fonts/Dosis-Light.ttf");
}

void PlayerGui::initLevelDisplay()
{
	float width = gui::p2pX(1.6f, this->vm);
	float height = gui::p2pY(2.8f, this->vm);
	float x = gui::p2pX(1.f, this->vm);
	float y = gui::p2pY(1.9f, this->vm);

	this->levelDisplayBack.setSize(sf::Vector2f(width, height));
	this->levelDisplayBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->levelDisplayBack.setPosition(x, y);

	this->levelDisplayText.setFont(this->font);
	this->levelDisplayText.setCharacterSize(gui::calcCharSize(this->vm, 200));
	this->levelDisplayText.setPosition(
		this->levelDisplayBack.getPosition().x + gui::p2pX(0.53f, this->vm),
		this->levelDisplayBack.getPosition().y + gui::p2pY(0.5f, this->vm)
	);
}

void PlayerGui::initEXPBar()
{
	float width = gui::p2pX(10.4f, this->vm);
	float height = gui::p2pY(1.9f, this->vm);
	float x = gui::p2pX(1.f, this->vm);
	float y = gui::p2pY(5.6f, this->vm);

	this->expBarMaxWidth = width;

	this->expBarBack.setSize(sf::Vector2f(width, height));
	this->expBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->expBarBack.setPosition(x, y);

	this->expBarInner.setSize(sf::Vector2f(width, height));
	this->expBarInner.setFillColor(sf::Color(20, 20, 250, 200));
	this->expBarInner.setPosition(this->expBarBack.getPosition());

	this->expBarText.setFont(this->font);
	this->expBarText.setCharacterSize(gui::calcCharSize(this->vm, 200));
	this->expBarText.setPosition(
		this->expBarBack.getPosition().x + gui::p2pX(0.53f, this->vm),
		this->expBarBack.getPosition().y + gui::p2pY(0.15f, this->vm)
	);
}

void PlayerGui::initHPBar()
{
	float width = gui::p2pX(10.4f, this->vm);
	float height = gui::p2pY(2.8f, this->vm);
	float x = gui::p2pX(1.f, this->vm);
	float y = gui::p2pY(8.3f, this->vm);

	this->hpBarMaxWidth = width;

	this->hpBarBack.setSize(sf::Vector2f(width, height));
	this->hpBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->hpBarBack.setPosition(x, y);

	this->hpBarInner.setSize(sf::Vector2f(width, height));
	this->hpBarInner.setFillColor(sf::Color(250, 20, 20, 200));
	this->hpBarInner.setPosition(this->hpBarBack.getPosition());

	this->hpBarText.setFont(this->font);
	this->hpBarText.setCharacterSize(gui::calcCharSize(this->vm, 160));
	this->hpBarText.setPosition(
		this->hpBarBack.getPosition().x + gui::p2pX(0.53f, this->vm),
		this->hpBarBack.getPosition().y + gui::p2pY(0.5f, this->vm)
	);
}

// Constructors and Destructors
PlayerGui::PlayerGui(Player* player, sf::VideoMode& vm)
	: vm(vm)
{
	this->player = player;

	this->initFont();
	this->initLevelDisplay();
	this->initHPBar();
	this->initEXPBar();
}

PlayerGui::~PlayerGui()
{

}

// Functions
void PlayerGui::updateLevelDisplay()
{
	this->levelDisplayString = std::to_string(this->player->getAttributeComponent()->level);
	this->levelDisplayText.setString(this->levelDisplayString);
}

void PlayerGui::updateHPBar()
{
	float percent = static_cast<float>(this->player->getAttributeComponent()->hp) / static_cast<float>(this->player->getAttributeComponent()->hpMax);

	this->hpBarInner.setSize(
		sf::Vector2f(
			static_cast<float>(std::floor(this->hpBarMaxWidth * percent)),
			this->hpBarInner.getSize().y
		)
	);

	this->hpBarString = std::to_string(this->player->getAttributeComponent()->hp) + "/" + std::to_string(this->player->getAttributeComponent()->hpMax);
	this->hpBarText.setString(this->hpBarString);
}

void PlayerGui::updateEXPBar()
{
	float percent = static_cast<float>(this->player->getAttributeComponent()->exp) / static_cast<float>(this->player->getAttributeComponent()->expNext);

	this->expBarInner.setSize(
		sf::Vector2f(
			static_cast<float>(std::floor(this->expBarMaxWidth * percent)),
			this->expBarInner.getSize().y
		)
	);

	this->expBarString = std::to_string(this->player->getAttributeComponent()->exp) + "/" + std::to_string(this->player->getAttributeComponent()->expNext);
	this->expBarText.setString(this->expBarString);
}

void PlayerGui::update(const float& dt)
{
	this->updateLevelDisplay();
	this->updateHPBar();
	this->updateEXPBar();
}

void PlayerGui::renderLevelDisplay(sf::RenderTarget& target)
{
	target.draw(this->levelDisplayBack);
	target.draw(this->levelDisplayText);
}

void PlayerGui::renderHPBar(sf::RenderTarget& target)
{
	target.draw(this->hpBarBack);
	target.draw(this->hpBarInner);
	target.draw(this->hpBarText);
}

void PlayerGui::renderEXPBar(sf::RenderTarget& target)
{
	target.draw(this->expBarBack);
	target.draw(this->expBarInner);
	target.draw(this->expBarText);
}

void PlayerGui::render(sf::RenderTarget& target)
{
	this->renderLevelDisplay(target);
	this->renderHPBar(target);
	this->renderEXPBar(target);
}
