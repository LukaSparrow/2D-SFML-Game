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
	std::vector< std::vector< std::vector< Tile > > > map;

public:
	TileMap();
	virtual ~TileMap();

	void update();
	void render(sf::RenderTarget& target);
};