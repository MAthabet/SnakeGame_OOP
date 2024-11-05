#include "Assets.h"
#include <string>

#include "GameDefinitions.h"

std::string const Spritesheet_Path = ".\\resources\\snake.png";

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
sf::IntRect cherryRect(6 * PIXIL_L, PIXIL_L, 3 * PIXIL_L, PIXIL_L);

sf::Texture spritesheet;

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







