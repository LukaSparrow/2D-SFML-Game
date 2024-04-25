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

public:
	TileMap(float gridSize, unsigned width, unsigned height);
	virtual ~TileMap();

	// Functions
	void addTile(const unsigned x, const unsigned y, const unsigned z);
	void removeTile();
	
	void update();
	void render(sf::RenderTarget& target);

};