#pragma once
#include "Assets.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameDefinitions.h"

extern Assest* world[HEIGHT_TILES_MAX][WIDTH_TILES_MAX];

class Map
{
public:
	sf::Vector2f PlayerTailStart;
	std::vector<int[2]> headStartPos;
	void draw(sf::RenderWindow* window);
	void deleteMap();
	void fileToArray();
private:
	void SpritetoWall(sf::Sprite* temp, int i, int j);
	void setPlayerTailStart(int i, int j);
};

