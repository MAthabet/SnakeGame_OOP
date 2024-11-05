#pragma once

#include <SFML/Graphics.hpp>

#include "GameDefinitions.h"
#include "Assets.h"
#include "Collidable.h"

enum class Direction { Up, Down, Left, Right };

class Snake: public Collidable
{
public:
	bool golden;
	Direction lastInput = Direction::Right;
	std::vector<sf::Sprite> snake;
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
	Collidable* checkCollision();
	void onCollision();
	void updatePosition();
private:
	void handleDeath();
	void updateDirection();
	bool checkSelfCollision();
	sf::Vector2i direction;
	sf::Vector2f tailStartPosition;
};