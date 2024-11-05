#pragma once

#include <SFML/Graphics.hpp>

#include "Collidable.h"

class Collectible: public Collidable
{
public:
	Collectible(sf::Sprite* s,int h);
	sf::Sprite* sprite;
	int score;
	void flip();
	void applyEffect();

};

