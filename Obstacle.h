#pragma once

#include <SFML/Graphics.hpp>

#include "Collidable.h"

class Obstacle: public Collidable
{
public:
	sf::Sprite sprite;
	virtual void onCollision() = 0;
};

