#pragma once

#include <SFML/Graphics.hpp>

#include "Collidable.h"

class Collectible: public Collidable
{
public:
	Collectible(sf::Sprite* sprite , Assets type);
};

