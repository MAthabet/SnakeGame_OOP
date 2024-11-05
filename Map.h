#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Snake.h"

int const WIDTH_TILES_MAX = 40;
int const HEIGHT_TILES_MAX = 24;

class Map
{
public:
	sf::Vector2f PlayerTailStart;
	sf::Sprite* map[HEIGHT_TILES_MAX][WIDTH_TILES_MAX] ;
	std::vector<int[2]> headStartPos;
	void draw(sf::RenderWindow* window);
	void deleteMap();
	void fileToArray();
private:
	void SpritetoWall(sf::Sprite* temp, int i, int j);
	sf::Vector2i playerTailStart(int i, int j);
	void setPlayerTailStart(int i, int j);
};

