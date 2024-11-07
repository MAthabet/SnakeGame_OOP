#include "GameDefinitions.h"
#include "Assets.h"



#pragma region Rects
//defining rect for each assest type
sf::IntRect headRect(4 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect headUpRect(1 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect headDownRect(3 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect headLeftRect(2 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect bodyRect(5 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L);

sf::IntRect wallUPRect(10 * PIXIL_L, 2 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect wallLeftRect(9 * PIXIL_L, 2 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect wallRightRect(8 * PIXIL_L, 2 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect wallDownRect(7 * PIXIL_L, 2 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect wallRect(12 * PIXIL_L, 0 * PIXIL_L, PIXIL_L, PIXIL_L);

sf::IntRect redObstacleRect(8 * PIXIL_L, 1 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect blueObstacleRect(8 * PIXIL_L, 0 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect rockRect(7 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect shurikenRect(6 * PIXIL_L, 6 * PIXIL_L, PIXIL_L, PIXIL_L);

sf::IntRect redAppleRect(6 * PIXIL_L, 0 * PIXIL_L, PIXIL_L, PIXIL_L);;
sf::IntRect greenAppleRect(6 * PIXIL_L, 4 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect goldenAppleRect(6 * PIXIL_L, 1 * PIXIL_L, PIXIL_L, PIXIL_L);
sf::IntRect cherryRect(6 * PIXIL_L, 3 * PIXIL_L, PIXIL_L, PIXIL_L);
#pragma endregion
sf::Texture spritesheet;

#pragma region Sprites
sf::Sprite head(spritesheet, headRect);
sf::Sprite headUp(spritesheet, headUpRect);
sf::Sprite headDown(spritesheet, headDownRect);
sf::Sprite headLeft(spritesheet, headLeftRect);
sf::Sprite body(spritesheet, bodyRect);

sf::Sprite wallUp(spritesheet, wallUPRect);
sf::Sprite wallLeft(spritesheet, wallLeftRect);
sf::Sprite wallRight(spritesheet, wallRightRect);
sf::Sprite wallDown(spritesheet, wallDownRect);
sf::Sprite wall(spritesheet, wallRect);

sf::Sprite redObstacle(spritesheet, redObstacleRect);
sf::Sprite blueObstacle(spritesheet, blueObstacleRect);
sf::Sprite rock(spritesheet, rockRect);
sf::Sprite shuriken(spritesheet, shurikenRect);

sf::Sprite redApple(spritesheet, redAppleRect);
sf::Sprite greenApple(spritesheet, greenAppleRect);
sf::Sprite goldenApple(spritesheet, goldenAppleRect);
sf::Sprite cherry(spritesheet, cherryRect);
#pragma endregion

void Assest::flip(float speed)
{
    float x = this->sprite->getScale().x;
    if (speed == 1)
    {
        x *= -speed;
        this->sprite->setScale(
            x,
            this->sprite->getScale().y);
        return;
    }
    
    //if (abs(x) < 0.24) inv = true;
    //else if(x > 0.95)inv = false;
    //if (inv)
    //    flipInv(speed);
    //else
    //{
    //    x *= speed;
    //    this->sprite->setScale(
    //        x,
    //        this->sprite->getScale().y);
    //    inv = true;
    //}
}

void Assest::rotate(float speed)
{
    this->sprite->rotate(speed);
}

void resizeAllAssets()
{
    int w, h;
    sf::Sprite* all[] = 
    {
        &head,&headUp,&headDown,&headLeft,&body,&wallUp,&wallLeft,&wallRight,&wallDown,
        &redObstacle,&blueObstacle,&rock,&shuriken,&redApple,&greenApple,&goldenApple,&cherry,&wall
    };
    for (sf::Sprite* sprite : all)
    {
        w = sprite->getLocalBounds().width;
        h = sprite->getLocalBounds().height;
        sprite->setScale(
            TILE_SIZE / w,
            TILE_SIZE / h);
        sprite->setOrigin(w / 2, h / 2);
    }

}

void Assest::flipInv(float speed)
{
    float x = this->sprite->getScale().x/-speed;
    this->sprite->setScale(
        x,
        this->sprite->getScale().y);
}

void move(float speed)
{

}







