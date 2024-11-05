#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameDefinitions.h"

enum Assets
{
	None, Head, Body, Wall, RedObstacle, BlueObstacle, Rock, Shuriken, RedApple, GreenApple, GoldenApple, Cherry, Window
};

struct Sprites
{
	sf::Sprite* sprite;
	Assets type;
	Sprites(sf::Sprite* s, Assets t) : sprite(s), type(t) {}
};

class Map
{
public:
	Sprites* map[HEIGHT_TILES_MAX][WIDTH_TILES_MAX];
	sf::Vector2f PlayerTailStart;
	std::vector<int[2]> headStartPos;
	void draw(sf::RenderWindow* window);
	void deleteMap();
	void fileToArray();
private:
	void SpritetoWall(sf::Sprite* temp, int i, int j);
	void setPlayerTailStart(int i, int j);
};

