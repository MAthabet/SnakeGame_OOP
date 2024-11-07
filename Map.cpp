#include "Map.h"
#include <fstream>

Assest* world[HEIGHT_TILES_MAX][WIDTH_TILES_MAX];

Map::Map()
{
}
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
void Map::fileToArray(std::string s) 
{
	std::string line;
	std::ifstream file(s); // Open for reading
	if (!file.is_open()) {
		std::ofstream outFile(s, std::ios::app); // Open for writing (creates if doesn't exist)
	}
	char c;
	for (int i = 0; i < HEIGHT_TILES_MAX;i++)
	{
		bool isThereChar = true;

		if (!std::getline(file, line))
		{
			isThereChar = false;
		}
		int size = line.size();
		for (int j = 0; j < WIDTH_TILES_MAX; j++)
		{
			if (isThereChar)
			{
				c = line[j];
				sf::Sprite* temp = (new sf::Sprite());
				Assets type = None;
				switch (c)
				{
				case '\0':
					emptyTiles.push_back({i,j});
					isThereChar = false;
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
					for (int k =0; k < SNAKE_INIT_SIZE; k++)
					{
						emptyTiles.push_back({ i,j });
						j++;
					}
					if (j > size)
						isThereChar = false;
					delete temp;
					break;
				}
				default:
					emptyTiles.push_back({ i,j });
					break;
				}
				if (type != None)
				{
					temp->setPosition(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2);
					world[i][j] = new Assest(temp, type);
				}
			}
			else emptyTiles.push_back(std::make_pair(i, j));
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
void Map::tileIsEmpty(std::pair<int, int> position)
{
	emptyTiles.push_back(position);
}

void Map::deleteMap()
{
	for (int i = 0; i < HEIGHT_TILES_MAX;i++)
	{
		for (int j = 0; j < HEIGHT_TILES_MAX; j++)
		{
			if(world[i][j])
			delete world[i][j];
		}
	}
}
