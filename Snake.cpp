#include "Snake.h"

#include <SFML/Graphics.hpp>

Snake::Snake(int snakeLength, sf::Vector2f start)
{
    tailStartPosition.x = start.x;
    tailStartPosition.y = start.y;
    head.setPosition(tailStartPosition);
    snake.push_back(head);
    for (int i = 1; i < snakeLength; i++)
    {
        body.setPosition(tailStartPosition);
        snake.push_back(body);
        this->move();
    }
}
void Snake::grow()
{
    sf::Sprite sprite = snake.back();

    snake.push_back(sprite);
}

void Snake::move()
{
    for (int i = snake.size()-1; i > 0; i--)
    {
        snake[i].setPosition(snake[i - 1].getPosition());
    }
    sf::Sprite temp = snake[0];
    updateDirection();
    snake[0].setPosition(temp.getPosition().x + direction.x * TILE_SIZE, direction.y * TILE_SIZE + temp.getPosition().y);
    updatePosition();
}

void Snake::setStartPosition(sf::Vector2f startPosition)
{
    tailStartPosition = startPosition;
}

void Snake::updateDirection()
{
    switch (lastInput)
    {
    case Direction::Up:
        direction = {0,-1};
        snake[0] = headUp;
        break;
    case Direction::Down:
        direction = { 0,1 };
        snake[0] = headDown;
        break;
    case Direction::Left:
        direction = { -1,0 };
        snake[0] = headLeft;
        break;
    case Direction::Right:
        direction = { 1,0 };
        snake[0] = head;
        break;
    default:
        break;
    }
}

void Snake::increaseHealth(int toIncrease)
{
    health += toIncrease;
}

bool Snake::isAlive()
{
    if (health <= 0) Alive = false;
    return Alive;
}

void Snake::setSpeed(int speed)
{
    this->speed = speed;
}

void Snake::onCollision(Map* game)
{
    if (checkCollisionWithWindow())
    {
        handleCollisionWithWindow();
    }
    else if (checkCollisionWithWall(game))
    {
        Alive = 0;
    }
    else if (checkCollisionWithCollectable(game))
    {
        ;
    }
    else if (checkSelfCollision())
    {
        health = 0;
    }
    return ;
}
bool Snake::checkSelfCollision()
{
    int x = snake[0].getPosition().x;
    int y = snake[0].getPosition().y;
    for (int i = snake.size()-1; i > 0 ;i--)
    {
        if (x == snake[i].getPosition().x)
            if (y == snake[i].getPosition().y)
                return true;
    }
    return false;
}
void Snake::updatePosition()
{
    this->position.x = snake[0].getPosition().x;
    this->position.y = snake[0].getPosition().y;
}
void Snake::handleCollisionWithWindow()
{
    int x = snake[0].getPosition().x;
    int y = snake[0].getPosition().y;
    if (x >= GAME_W_MAX)
        snake[0].setPosition(0+ TILE_SIZE / 2,y);
    else if (x <= 0)
        snake[0].setPosition(GAME_W_MAX+TILE_SIZE/2, y);
    else if (y <= 0)
        snake[0].setPosition(x, GAME_H_MAX+ TILE_SIZE / 2);
    else if (y >= GAME_H_MAX)
        snake[0].setPosition(x, 0+ TILE_SIZE / 2);
}
//TODO
void handleDeath()
{

}


