#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Assets.h"
#include "Snake.h"
#include "Map.h"

int main()
{
    
    resizeAllAssets();

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(GAME_W_MAX, GAME_H_MAX), "Snake Game Test");
    window.setFramerateLimit(3);
    // Load the sprite sheet
    if (!spritesheet.loadFromFile(Spritesheet_Path)) {
        std::cerr << "Error loading sprite sheet!" << std::endl;
        return -1;
    }  

    Map map;
    map.fileToArray();

    Snake playerSnake = Snake(SNAKE_INIT_SIZE, map.PlayerTailStart);

    // Run the program as long as the window is open
    while (window.isOpen()) {
        // Check for all window events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // handle player input
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && playerSnake.lastInput != Direction::Down)
            playerSnake.lastInput = Direction::Up;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && playerSnake.lastInput != Direction::Up)
            playerSnake.lastInput = Direction::Down;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerSnake.lastInput != Direction::Left)
            playerSnake.lastInput = Direction::Right;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerSnake.lastInput != Direction::Right)
            playerSnake.lastInput = Direction::Left;

        playerSnake.move();
        playerSnake.onCollision(&map);
        
        // Clear the screen
        window.clear();
        
        // Display everything on the window
        
        map.draw(&window);
        if (playerSnake.isAlive())
        {
            for (auto& spirit : playerSnake.snake)
            {
                window.draw(spirit);
            }
        }
        window.display();
    }

    return 0;
}
