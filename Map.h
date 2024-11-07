#pragma once
#include "Assets.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameDefinitions.h"

extern Assest* world[HEIGHT_TILES_MAX][WIDTH_TILES_MAX];
extern std::vector<std::pair<int, int>> emptyTiles;

class Map
{
public:
	sf::Vector2f PlayerTailStart;
	
	void draw(sf::RenderWindow* window);
	void deleteMap();
	void fileToArray(std::string s);
	void tileIsEmpty(std::pair<int, int> position);

	Map();

private:
	void SpritetoWall(sf::Sprite* temp, int i, int j);
	void setPlayerTailStart(int i, int j);

};

