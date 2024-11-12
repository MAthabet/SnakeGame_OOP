#include "Snake.h"

#include <SFML/Graphics.hpp>

Snake::Snake()
{

}
void Snake::initSnake(int snakeLength, sf::Vector2f start, Map* map)
{
    tailStartPosition.x = start.x;
    tailStartPosition.y = start.y;
    this->map = map;
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
    health++;
    snake.push_back(sprite);
}

void Snake::shrink()
{
    if (health < 1)
    {
        handleDeath();
        return;
    }
    health--;
    snake.pop_back();
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

void Snake::checkSelfCollision()
{
    int x = snake[0].getPosition().x;
    int y = snake[0].getPosition().y;
    for (int i = snake.size()-1; i > 0 ;i--)
    {
        if (x == snake[i].getPosition().x)
            if (y == snake[i].getPosition().y)
                handleDeath();
    }
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
    collidedWithWin = true;
}
void Snake::handleCollisionWithCollectable()
{
    switch (colidedWith->type)
    {
    case RedApple:
    case GreenApple:
        Score += colidedWith->type * 10;
        collectedApples++;
        haseEatenApple = true;
        grow();
        break;
    case GoldenApple:
        shielded = true;
        Score += GoldenApple * 10;
        collectedApples++;
        break;
    case Cherry:
        Score += Cherry * 10;
        invertedInput = false;
        break;
    default:
        break;
    }
    DeleteTile(colidedWith->sprite->getPosition().x / TILE_SIZE, colidedWith->sprite->getPosition().y / TILE_SIZE);
}
void Snake::handleCollisionWithMovingObstacle(Assest* assest, int collidedHere)
{
    if (!shielded)
    {
        switch (assest->type)
        {
        case Rock:
            // if hit head invert ether shrink
            if(collidedHere == 0)
                invertedInput = true;
            else
                shrink();
            break;
        case Shuriken:
            cut(collidedHere);
            break;
        default:
            break;
        }
    }
}
void Snake::handleCollisionWithStationryObstacle()
{
    if(!shielded)
    switch (colidedWith->type)
    {
    case Wall:
        handleDeath();
        break;
    case RedObstacle:
    {
        int temp = direction.x;
        direction.x = direction.y;
        direction.y = temp;
        goto exit;
    }
        break;
    case BlueObstacle:
        shrink();
        goto exit;
        break;
    default:
        break;
    }
    DeleteTile(colidedWith->sprite->getPosition().x / TILE_SIZE, colidedWith->sprite->getPosition().y / TILE_SIZE);
exit:
    shielded = false;
}
void Snake::handleCollisionWithWall()
{
    if (shielded)
    {
        shielded = false;
        DeleteTile(colidedWith->sprite->getPosition().x / TILE_SIZE, colidedWith->sprite->getPosition().y / TILE_SIZE);
        return;
    }
    handleDeath();
}
bool Snake::checkCollision()
{
    bool isColided = false;
    int j = position.x / TILE_SIZE;
    int i = position.y / TILE_SIZE;

    //jumping over wall bug
    if (collidedWithWin)
    {
        collidedWithWin = false;
        if (j >= WIDTH_TILES_MAX) j = 0;
        else if (j <= 0) j = WIDTH_TILES_MAX - 1;
        else if (i >= HEIGHT_TILES_MAX) i = 0;
        else if (i <= 0) i = HEIGHT_TILES_MAX - 1;
        goto second_check;
    }
    if (checkCollisionWithWindow())
    {
        handleCollisionWithWindow();
        checkCollision();
        Assest* colidedWith = NULL;
        return true;
    }
second_check:
    Assets current;
    if (world[i][j])
    {
        current = world[i][j]->type;
        if(world[i][j])
        this->colidedWith = world[i][j];
        switch (current)
        {
        case Wall:
            handleCollisionWithWall();
            isColided = true;
            break;
        case RedObstacle:
        case BlueObstacle:
            handleCollisionWithStationryObstacle();
            isColided = true;
            break;
        case RedApple:
        case GreenApple:
        case GoldenApple:
        case Cherry:
            handleCollisionWithCollectable();
            isColided = true;
            break;
        default:
            break;
        }
    }
    return isColided;
}
//TODO
void Snake::handleDeath()
{
    Alive = false;
}
void Snake::draw(sf::RenderWindow* win)
{
    for (auto& spirit : snake)
    {
        win->draw(spirit);
    }
}
void Snake::cut(int collidedHere)
{
    for (int i = health - collidedHere; i > 0; i--)
    {
        shrink();
    }
}


