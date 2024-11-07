#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Assets.h"
#include "Snake.h"
#include "Map.h"
#include "Generator.h"
#include "Game.h"
int main()
{
    Game game;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(GAMEwin_W_MAX, GAMEwin_H_MAX), "Snake Game Test");
    window.setFramerateLimit(GAME_SPEED);
    // Load the sprite sheet
    
    // Run the program as long as the window is open
    while (window.isOpen()) 
    {
        // Check for all window events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
            game.run();
            break;
    }

    return 0;
}
