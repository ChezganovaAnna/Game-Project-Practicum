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
