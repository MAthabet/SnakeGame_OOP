#include "Map.h"
#include <fstream>

Assest* world[HEIGHT_TILES_MAX][WIDTH_TILES_MAX];

void Map::draw(sf::RenderWindow* window)
{
	if (window)
	{
		for (int i = 0; i < HEIGHT_TILES_MAX;i++)
		{
			for (int j = 0; j < WIDTH_TILES_MAX; j++)
			{
				if(world[i][j])
					if(world[i][j]->sprite)
						window->draw(*(world[i][j]->sprite));
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
			Assets type = None;
			switch (c)
			{
			case '\0':
				goto exit_loop;
				break;
			case 'w':
			case 'W':
				SpritetoWall(temp, i, j);
				type = Wall;
				break;
			case 'r':
			case 'R':
				*temp = redObstacle;
				type = RedObstacle;
				break;
			case 'b':
			case 'B':
				*temp = blueObstacle;
				type = BlueObstacle;
				break;
			case 's':
			case 'S':
			{
				setPlayerTailStart(i, j);
				j += SNAKE_INIT_SIZE - 1;
				delete temp;
				break;
			}
			default:
				delete temp;
				break;
			}
			if (type != None)
			{
				temp->setPosition(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2);
				world[i][j] = new Assest(temp, type);
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
			delete &world[i][j];
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

