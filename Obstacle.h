#pragma once

#include <SFML/Graphics.hpp>

#include "Effect.h"

enum Obstacles { redObstacle, blueObstacle, rock, shuriken };

class Obstacle: public Effect
{
public:
	Obstacles type;
	sf::Sprite sprite;

};

