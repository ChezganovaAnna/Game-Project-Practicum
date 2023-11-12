#include <SFML/Graphics.hpp>

class Game
{
  public:
    Game();
    void run();

  private:
    void ProcessEvents();
    void update();
    void render();

  private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
}

Game::Game()
    : mWindow(sf::VideoMode(640, 480), "SFML Application"), mPlayer()
{
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlyer.SetFillColor(sf::Color::Cyan);
}

void Game::run()
{
    while (mWindow.isOpen())
    {
        ProcessEvents();
        update();
        render();
    }
}

int main()
{
    Game game;
    game.run();
    // sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
    // sf::CircleShape shape;
    // shape.setRadius(40.f);
    // shape.setPosition(100.f, 100.f);
    // shape.SetFillColor(sf::Color::Cyan);
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == = sf::Event::Closed)
    //             window.close();
    //     }
    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }
}