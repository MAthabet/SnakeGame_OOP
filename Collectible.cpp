#include "Collectible.h"

Collectible::Collectible(Collectables t, sf::Sprite* s, int h)
{
    type = t;
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

