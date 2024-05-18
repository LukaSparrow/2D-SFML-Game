#pragma once

#include"Tile.h"
#include"Entity.h"

class Tile;
class Entity;

class TileMap
{
private:
	void clear();

	unsigned gridSizeU;
	float gridSizeF;
	sf::Vector2u maxSize;
	unsigned layers;
	std::vector< std::vector< std::vector< Tile* > > > map;
	std::string textureFile;
	sf::Texture tileSheet;
	sf::RectangleShape collisionBox;

public:
	TileMap(float gridSize, unsigned width, unsigned height, std::string texture_file);
	virtual ~TileMap();

	// Accessors
	const sf::Texture* getTileSheet() const;

	// Functions
	void addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect, const bool& collision, const short type);
	void removeTile(const unsigned x, const unsigned y, const unsigned z);
	void saveToFile(const std::string file_name);
	void loadFromFile(const std::string file_name);

	void updateCollision(Entity* entity);

	void update();
	void render(sf::RenderTarget& target, Entity* entity = nullptr);

};