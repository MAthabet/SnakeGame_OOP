#include "Game.h"

Collectible* AllCollectables[COLLECTIBLES_N];
MovingObstacle* AllMovingObs[MOVING_OBSTACLES_N];

Game::Game()
{
	return;
}
void Game::run()
{
    start();
    if (IsRunning)
    {
        loop();
    }
}
void Game::loop()
{

	while (IsRunning && window.isOpen())
	{
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleinput();

        player.move();

        generateCollictable(&collecablesGenerator);
        generateMovingObs();

        player.checkSelfCollision();
        player.checkCollision();
        
        // Clear the screen
        window.clear();

        map.draw(&window);
        if (player.isAlive())
        {
            for (auto& spirit : player.snake)
            {
                window.draw(spirit);
            }
        }

        window.display();
	}
	end();
}
void Game::start()
{
	loadSpritesheet();
	resizeAllAssets();
	openGameWin();
	updateAllCollectables();
	updateAllMovingObs();
    window.create(sf::VideoMode(GAME_W_MAX, GAME_H_MAX), "Snake Game");
	window.setFramerateLimit(GAME_SPEED);
	map.fileToArray(Resources_map);
	player.initSnake(SNAKE_INIT_SIZE, map.PlayerTailStart, &map);
	IsRunning = true;
}
void Game::end()
{
	IsRunning = false;
    map.deleteMap();
}
void Game::restart()
{
	IsRunning = true;

}
void Game::handleDeath()
{

}
void Game::generateCollictable(Generator* collectableGen)
{
    if (player.colidedWith == NULL)
    {
        generateApple();
        player.haseEatenApple = false;
    }
    else if (player.collectedApples+1 % 5 != 0 && (player.colidedWith->type == Assets::RedApple || player.colidedWith->type == Assets::GreenApple))
    {
            generateApple();
            player.haseEatenApple = false;
    }
    else  generateGoldenApple();
}
void Game::generateMovingObs()
{

}
void Game::generateApple()
{
    std::pair<int,int> rand = collecablesGenerator.generateEmptyTile();
    if (((player.collectedApples + 1) % 4) == 0)
    {
        collecablesGenerator.generate(GreenApple, rand.first, rand.second);
        printf("herre");
    }
    else
        collecablesGenerator.generate(RedApple, rand.first, rand.second);
}
void Game::generateGoldenApple()
{
    std::pair<int, int> rand = collecablesGenerator.generateEmptyTile();
    collecablesGenerator.generate(GoldenApple, rand.first, rand.second);
}
void Game::generateCherry()
{

}
void Game::generateRock()
{

}
void Game::generateShuriken()
{

}
void Game::openGameWin()
{
	sf::RenderWindow window(sf::VideoMode(GAME_W_MAX, GAME_H_MAX), "Snake Game Test");
	window.setFramerateLimit(GAME_SPEED);
}

int Game::loadSpritesheet()
{
	if (!spritesheet.loadFromFile(Spritesheet_Path)) 
	{
		return -1;
	}
}

void Game::updateAllCollectables()
{
	AllCollectables[0] = new Collectible(&redApple, Assets::RedApple);
	AllCollectables[1] = new Collectible(&greenApple, Assets::GreenApple);
	AllCollectables[2] = new Collectible(&goldenApple, Assets::GoldenApple);
	AllCollectables[3] = new Collectible(&cherry, Assets::Cherry);
}

void Game::updateAllMovingObs()
{
	AllMovingObs[0] = new MovingObstacle(&rock, Assets::Rock);
	AllMovingObs[1] = new MovingObstacle(&shuriken, Assets::Shuriken);
}
void Game::handleinput()
{
    if (player.invertedInput)
    {
        invertInput();
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.lastInput != Direction::Down)
        player.lastInput = Direction::Up;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.lastInput != Direction::Up)
        player.lastInput = Direction::Down;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.lastInput != Direction::Left)
        player.lastInput = Direction::Right;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.lastInput != Direction::Right)
        player.lastInput = Direction::Left;
}
void Game::invertInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.lastInput != Direction::Up)
        player.lastInput = Direction::Down;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.lastInput != Direction::Down)
        player.lastInput = Direction::Up;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.lastInput != Direction::Right)
        player.lastInput = Direction::Left;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.lastInput != Direction::Left)
        player.lastInput = Direction::Right;
}