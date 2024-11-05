#include "Map.h"
#include "Assets.h"
#include <fstream>
void Map::draw(sf::RenderWindow* window)
{
	if (window)
	{
		for (int i = 0; i < HEIGHT_TILES_MAX;i++)
		{
			for (int j = 0; j < WIDTH_TILES_MAX; j++)
			{
				if(map[i][j])
				window->draw(*(map)[i][j]);
			}
		}
	}
}
void Map::fileToArray() 
{
	std::string line;
	std::ifstream file(".\\resources\\input.txt"); // Open for reading
	if (!file.is_open()) {
		std::ofstream outFile(".\\resources\\input.txt", std::ios::app); // Open for writing (creates if doesn't exist)
	}
	char c;
	for (int i = 0; i < HEIGHT_TILES_MAX;i++)
	{

		if (!std::getline(file, line))
		{
			break;
		}

		int j = 0;
		int min = line.size() < WIDTH_TILES_MAX ? line.size(): WIDTH_TILES_MAX;

		for (; j < min; j++)
		{
			c = line[j];
			sf::Sprite* temp = (new sf::Sprite());
			switch (c)
			{
			case '\0':
				goto exit_loop;
				break;
			case 'w':
			case 'W':
				SpritetoWall(temp, i, j);
				break;
			case 'r':
			case 'R':
				*temp = redObstacle;
				break;
			case 'b':
			case 'B':
				*temp = blueObstacle;
				break;
			case 's':
			case 'S':
			{
				setPlayerTailStart(i, j);
				j += SNAKE_INIT_SIZE - 1;
				temp = NULL;
				break;
			}
			default:
				temp = NULL;
				break;
			}
			if (temp)
			{
				temp->setPosition(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2);
				map[i][j] = temp;
			}
		}
	exit_loop:;
	}
}
void Map::deleteMap()
{
	for (int i = 0; i < HEIGHT_TILES_MAX;i++)
	{
		for (int j = 0; j < HEIGHT_TILES_MAX; j++)
		{
			delete &map[i][j];
		}
	}
}
void Map::SpritetoWall(sf::Sprite* temp, int i, int j)
{
	if (i == 0)
	{
		*temp = wallUp;
	}
	else if (i == WIDTH_TILES_MAX - 1)
	{
		*temp = wallDown;
	}
	else if (j == 0)
	{
		*temp = wallLeft;
	}
	else if (j == WIDTH_TILES_MAX - 1)
	{
		*temp = wallRight;
	}
	else *temp = wall;
}
void Map::setPlayerTailStart(int i, int j)
{
	PlayerTailStart = {(float) j * TILE_SIZE + +TILE_SIZE / 2,(float) i * TILE_SIZE+ TILE_SIZE / 2 };
}
