#pragma once

#include <SFML/Graphics.hpp>

#include "Effect.h"
enum Collectables {RedApple, GreenApple, GoldenApple, Cherry};

class Collectible: public Effect
{
public:
	Collectible(Collectables t, sf::Sprite* s,int h);
	Collectables type;
	sf::Sprite* sprite;
	int score;
	void flip();
	void applyEffect();

};

