#include "Game.h"
#include <cstdlib>

Collectible* AllCollectables[COLLECTIBLES_N];
MovingObstacle* AllMovingObs[MOVING_OBSTACLES_N];
void Game::displayScore()
{
    sf::Font font;
    if (!font.loadFromFile(Font_Path)) {
        printf("can not load font");
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(50); 
    scoreText.setFillColor(sf::Color::White); 
    scoreText.setPosition(0,0); 
    scoreText.setString("Score: " + std::to_string(player.Score));
    window.draw(scoreText);
}
void Game::displayRestart()
{
    sf::Font font;
    if (!font.loadFromFile(Font_Path)) {
        printf("can not load font");
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(GAME_W_MAX/2, GAME_H_MAX/2);
    scoreText.setString("YOU DIED!\nPRESS R to restart");
    window.draw(scoreText);
}
Game::Game()
{
    return;
}
void Game::run()
{
    start();
    loop();
    restart();
}

void Game::loop()
{
    Generator foodGenerator{ sf::seconds(APPLE_COOLDOWN_TIME), &map };
    Generator ShurikenGenerator{ sf::seconds(SHURIKEN_COOLDOWN_TIME), &map };
    Generator RockGenerator{ sf::seconds(ROCK_COOLDOWN_TIME), &map };

    sf::Clock goldenAppleClock;
    sf::Time goldenAppleTime = sf::seconds(GOLDEN_APPLE_TIME);
    Generator goldenAppleGenerator{&map};
    bool goldenAppleOnScreen_flag = false;

    sf::Clock cherryClock;
    sf::Time cherryCoolDownTime = sf::seconds(CHERRY_COOLDOWN_TIME);
    sf::Time cherryLife = sf::seconds(CHERRY_TIME);
    Generator cherryGenerator{&map}; 

    srand(time(0));
    while (player.Alive && window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        handleinput();

        player.move();
        moveAllObs();
        flipAllcol();

        generateFood(&foodGenerator);

        if (goldenAppleGenerator.hasGenerated() && goldenAppleClock.getElapsedTime() > goldenAppleTime)
        {
            goldenAppleGenerator.deleteLastGenerated();
            goldenAppleOnScreen_flag = false;
        }
        else if (!goldenAppleOnScreen_flag && (player.collectedApples + 1) % 10 == 0)
        {
            generateGoldenApple(&goldenAppleGenerator);
            goldenAppleClock.restart();
            goldenAppleOnScreen_flag = true;
        }

        
        if (cherryClock.getElapsedTime() > cherryCoolDownTime)
        {
            generateCherry(&cherryGenerator);
            cherryClock.restart();
        }
        else if (cherryClock.getElapsedTime() > cherryLife)
        {
            cherryGenerator.deleteLastGenerated();
        }

        generateRock(&RockGenerator);
        generateShuriken(&ShurikenGenerator);

        player.checkSelfCollision();
        player.checkCollision();
        for (int i = 0; i < MOVING_OBSTACLES_N; i++)
        {
            AllMovingObs[i]->checkCollisionWithSnake(&player);
        }


        // Clear the screen
        window.clear();

        map.draw(&window);
        if (player.Alive)
        {
            player.draw(&window);
        }
        displayScore();
        
        window.display();
    }
   
}
void Game::start()
{
    loadSpritesheet();
    resizeAllAssets();
    updateAllCollectables();
    updateAllMovingObs();

    openGameWin();
    
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
    displayRestart();
    window.display();
    while (!player.Alive)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) player.Alive = true;
    }
}
void Game::handleDeath()
{

}

Collidable* Game::generateFood(Generator* generator)
{
    if (player.haseEatenApple)
    {
        player.haseEatenApple = false;
        return forceGenerateApple(generator);
    }
    if (player.colidedWith == NULL) //Just Guard
    {
        generateApple(generator);
        player.haseEatenApple = false;
    }
    else if ((player.collectedApples + 1) % 5 != 0 && (player.colidedWith->type == Assets::RedApple || player.colidedWith->type == Assets::GreenApple))
    {
        generateApple(generator);
        player.haseEatenApple = false;
    }
}
Collidable* Game::generateApple(Generator* generator)
{
    std::pair<int,int> rand = generator->generateEmptyTile();
    if (((player.collectedApples + 1) % 4) == 0)
    {
        return generator->generate(GreenApple, rand.first, rand.second);
    }
    else
        return generator->generate(RedApple, rand.first, rand.second);
}
Collidable* Game::forceGenerateApple(Generator* generator)
{
        std::pair<int, int> rand = generator->generateEmptyTile();
        if (((player.collectedApples + 1) % 4) == 0)
        {
            return generator->forceGenerate(GreenApple, rand.first, rand.second);
        }
        else
            return generator->forceGenerate(RedApple, rand.first, rand.second);
}
Collidable* Game::generateGoldenApple(Generator* generator)
{
        std::pair<int, int> rand = generator->generateEmptyTile();
        return generator->generate(GoldenApple, rand.first, rand.second);
}
Collidable* Game::generateCherry(Generator* generator)
{
    int rndm = rand() % 101;
    if (rndm < 11)
    {
        std::pair<int, int> rand = generator->generateEmptyTile();
        return generator->generate(Cherry, rand.first, rand.second);

    }

    return NULL;
}
Collidable* Game::generateRock(Generator* generator)
{
    std::pair<int, int> rand = generator->generateEmptyTile();
    //return generator->generate(Rock, 0, rand.second
    return generator->generate(Rock, 0, 2);
}
Collidable* Game::generateShuriken(Generator* generator)
{
    int rndm = rand() % HEIGHT_TILES_MAX;
    return generator->generate(Shuriken, rndm, 0);
}

void Game::openGameWin()
{
    window.create(sf::VideoMode(GAMEwin_W_MAX, GAMEwin_H_MAX), "Snake Game");
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
	AllMovingObs[0] = new MovingObstacle(&rock, Assets::Rock, Axis::Vertical);
	AllMovingObs[1] = new MovingObstacle(&shuriken, Assets::Shuriken, Axis::Horizontal);
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

void Game::moveAllObs(float speed)
{
    for (int i = 0; i < MOVING_OBSTACLES_N; i++)
    {
        AllMovingObs[i]->move(speed);
    }
}
void Game::flipAllcol(float speed)
{
    for (int i = 0; i < COLLECTIBLES_N; i++)
    {
        AllCollectables[i]->assest.flip();
    }
}