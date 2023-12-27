#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class Button
{
public:
    void init();
    void render(sf::RenderWindow& window);
    void render(sf::RenderWindow& window, int x, int y);
    void Reaction();
    sf::Sprite sprite;
private:    
    sf::Texture texture;
    
};

void Button::init() {

    if (!texture.loadFromFile("./src/tileset/Tile_36.png")) {
        std::cout << "Error loading texture" << std::endl;
    }
    sprite.setTexture(texture);
}

void Button::render(sf::RenderWindow& window) {
    window.draw(sprite);
}



void Button::render(sf::RenderWindow& window, int x, int y) {
    sprite.setPosition(x, y);
    sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    window.draw(sprite);
}


void Button::Reaction()
{
    sf::Texture emptyTexture;
    emptyTexture.create(1, 1);

    // Установка пустой текстуры для спрайта
    sprite.setTexture(emptyTexture);
}