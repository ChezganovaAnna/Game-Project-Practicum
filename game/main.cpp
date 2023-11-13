#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "Entities/entity.hpp"

class Game
{
  public:
    Game();
    void run();

  private:
    void InitSpriteMainCharacter();
    void ProcessEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow mWindow;
    sf::Texture mTexture;
    sf::Sprite mPlayer;

    bool mIsMovingUp = false;
    bool mIsMovingDown = false;
    bool mIsMovingLeft = false;
    bool mIsMovingRight = false;
};

Game::Game()
    : mWindow(sf::VideoMode(640, 480), "SFML Application"), mPlayer()
{
    InitSpriteMainCharachter();
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

    while (mWindow.isOpen())
    {
        ProcessEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            ProcessEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::ProcessEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key,
                             bool isPressed)
{
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f PlayerSpeed(100.f, 100.f);
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
        movement.y -= PlayerSpeed.y;
    if (mIsMovingDown)
        movement.y += PlayerSpeed.y;
    if (mIsMovingLeft)
        movement.x -= PlayerSpeed.x;
    if (mIsMovingRight)
        movement.x += PlayerSpeed.x;

    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::InitSpriteMainCharacter()
{
    if (!mTexture.loadFromFile("./src/undertale-main-character.png"))
        std::cout << "I can't connect the picture" << std::endl;
    mPlayer.setTexture(mTexture);
    mPlayer.setScale(0.15f, 0.15f);
    mPlayer.setPosition(100.f, 100.f);
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

int main()
{
    Game game;
    game.run();
}

//Game.hpp