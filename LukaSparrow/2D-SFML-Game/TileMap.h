#pragma once

#include"Tile.h"

class Tile;

class TileMap
{
private:
	unsigned gridSizeU;
	float gridSizeF;
	sf::Vector2u maxSize;
	unsigned layers;
	std::vector< std::vector< std::vector< Tile* > > > map;
	sf::Texture tileSheet;

public:
	TileMap(float gridSize, unsigned width, unsigned height);
	virtual ~TileMap();

	// Accessors
	const sf::Texture* getTileSheet() const;

	// Functions
	void addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect);
	void removeTile(const unsigned x, const unsigned y, const unsigned z);
	
	void update();
	void render(sf::RenderTarget& target);

};