#pragma once

#include <SFML/Graphics.hpp>

class Game
{
	public :
	sf::Clock clock;
	sf::Time time = clock.getElapsedTime();
	sf::Int64 microseconds = time.asMicroseconds();

};

