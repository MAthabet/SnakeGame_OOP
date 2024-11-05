#pragma once

#include <SFML/Graphics.hpp>

#include "Assets.h"
#include "Collision.h"

int const SNAKE_INIT_SIZE = 3;

enum class Direction { Up, Down, Left, Right };

class Snake: public Collision
{
public:
	Direction lastInput = Direction::Right;
	std::vector<sf::Sprite> snake;
	sf::Sprite collidedWith;
	int health = SNAKE_INIT_SIZE;
	int speed;
	
	Snake(int snakeLength) : Snake(snakeLength, tailStartPosition) {};
	Snake(int snakeLength, sf::Vector2f start);

	void grow();
	void move();
	void setStartPosition(sf::Vector2f startPosition);
	void increaseHealth(int toIncrease);
	bool isAlive();
	void setSpeed(int speed);

private:
	void updateDirection();

	
	sf::Vector2i direction;
	sf::Vector2f tailStartPosition;
};