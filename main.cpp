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
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(GAMEwin_W_MAX, GAMEwin_H_MAX), "Snake Game Strucured");
    window.setFramerateLimit(GAME_SPEED);
    // Load the sprite sheet
    
    // Run the program as long as the window is open
    while (window.isOpen()) 
    {
        Game game;
        // Check for all window events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
            game.run();
            if(!game.IsRunning)
                break;
    }

    return 0;
}
