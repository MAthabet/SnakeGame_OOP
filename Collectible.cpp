#include "Collectible.h"

Collectible::Collectible(sf::Sprite* s, int h)
{
    sprite = s;
    score = h;
}

void Collectible::flip()
{
    sprite->setScale(
        -1 * sprite->getScale().x,
        sprite->getScale().y);
}

void Collectible::applyEffect()
{

}

