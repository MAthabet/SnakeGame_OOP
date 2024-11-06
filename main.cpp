#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Assets.h"
#include "Snake.h"
#include "Map.h"
#include "Generator.h"

int main()
{
    
    resizeAllAssets();
    Generator generator(sf::seconds(5));
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(GAME_W_MAX, GAME_H_MAX), "Snake Game Test");
    window.setFramerateLimit(GAME_SPEED);
    // Load the sprite sheet
    if (!spritesheet.loadFromFile(Spritesheet_Path)) {
        std::cerr << "Error loading sprite sheet!" << std::endl;
        return -1;
    }  
    Map map;
    map.fileToArray();

    Snake playerSnake = Snake(SNAKE_INIT_SIZE, map.PlayerTailStart);
    Collidable* temp = NULL;
    bool flag = true;
    // Run the program as long as the window is open
    while (window.isOpen()) {
        // Check for all window events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // handle player input
        if (playerSnake.invertedInput)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && playerSnake.lastInput != Direction::Down)
                playerSnake.lastInput = playerSnake.invertedInput ? Direction::Down : Direction::Up;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && playerSnake.lastInput != Direction::Up)
                playerSnake.lastInput = playerSnake.invertedInput ? Direction::Up : Direction::Down;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerSnake.lastInput != Direction::Left)
                playerSnake.lastInput = playerSnake.invertedInput ? Direction::Left : Direction::Right;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerSnake.lastInput != Direction::Right)
                playerSnake.lastInput = playerSnake.invertedInput ? Direction::Right : Direction::Left;
        }
        else
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && playerSnake.lastInput != Direction::Down)
                playerSnake.lastInput = Direction::Up;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && playerSnake.lastInput != Direction::Up)
                playerSnake.lastInput = Direction::Down;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerSnake.lastInput != Direction::Left)
                playerSnake.lastInput = Direction::Right;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerSnake.lastInput != Direction::Right)
                playerSnake.lastInput = Direction::Left;
        }

        playerSnake.move();

        playerSnake.checkCollision();
        playerSnake.checkSelfCollision();

        // Clear the screen
        window.clear();
        
        // Display everything on the window
        Collidable* temp2 = generator.generate(Cherry, 10, 10);
        generator.generate(GoldenApple, 5, 5);
        if (temp2)
            temp = temp2;
        else if (temp && flag)
        {
            temp->assest.flip(0.5);
        }


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
