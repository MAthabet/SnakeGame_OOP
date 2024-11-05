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
    snake[0].setPosition(temp.getPosition().x + direction.x * TILE_L * PIXIL_L, direction.y * TILE_L * PIXIL_L + temp.getPosition().y);
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
    if (health > 0) return true;
    return false;
}

void Snake::setSpeed(int speed)
{
    this->speed = speed;
}

Collidable* Snake::checkCollision()
{
    if (!checkCollisionWithWindow())
    {

    }
    else if (!checkCollisionWithWall())
    {

    }
    else if (!checkCollisionWithCollidable())
    {

    }
    else if (!checkSelfCollision())
    {
        return NULL;
    }
    return NULL;
}
bool Snake::checkSelfCollision()
{
    for (int i = 0; i < health;i++)
    {
        if (snake[0].getPosition().x == snake[i].getPosition().x)
            if (snake[0].getPosition().y == snake[i].getPosition().y)
                return true;
    }
    return false;
}
void Snake::onCollision()
{
    return;
}
void Snake::updatePosition()
{
    this->position.x = snake[0].getPosition().x;
    this->position.y = snake[0].getPosition().y;
}
//TODO
void handleDeath()
{

}

