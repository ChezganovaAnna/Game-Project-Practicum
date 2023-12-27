    #include <SFML/Graphics.hpp>
    #include <cmath>
    #include <iostream>
    #include <Windows.h>
 
    #include "Entities/Button.h"

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
            void resetGame();

            void CollisionX();
            void CollisionY();

            void initMap();
            void drawMap(sf::RenderWindow& window);
            void drawBackground(sf::RenderWindow& window);
            static const int mapHeight = 16;
            static const int mapWidth = 41;
            sf::String TileMap[mapHeight];
            sf::Texture mTileTexture;
            sf::Sprite mTileSprite;


            sf::Texture mTileTextureBound;
            sf::Sprite mTileSpriteBound;

            sf::Texture mTileTextureGround;
            sf::Sprite mTileSpriteGround;


            sf::Texture mTileTextureBox;
            sf::Sprite mTileSpriteBox;

            sf::Texture mTileTextureDoor;
            sf::Sprite mTileSpriteDoor;

            sf::Texture mTileTextureSkull;
            sf::Sprite mTileSpriteSkull;

            sf::Texture mBackgroundTexture;
            sf::Sprite mBackgroundSprite;

            

            sf::RenderWindow mWindow;
            sf::Texture mTexture;
            sf::Sprite mPlayer;
            float currentFrame;
            sf::FloatRect rect;
            sf::RectangleShape rect1;
            bool onGround;
            float dx, dy;
            float gravity = 9.8f;
            int jumpCount;
            bool doubleJumpAvailable = false;
            bool mIsMovingUp = false;
            bool mIsMovingDown = false;
            bool mIsMovingLeft = false;
            bool mIsMovingRight = false;
            Button button;

            bool showMissionText = true;

            bool life;
            int health;
        };



    Game::Game()
    : mWindow(sf::VideoMode(800, 500), "SFML Application"), mPlayer()
    {
        InitSpriteMainCharacter();
        initMap();
    }

    void Game::run()
    {
        sf::Clock clock;    
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
        button.init(); 
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
                if (event.key.code == sf::Keyboard::Tab) {
                    resetGame();
                }
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


    void Game::resetGame() {
        InitSpriteMainCharacter();
        initMap();
    }

    void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
    {
        if (key == sf::Keyboard::W)
        {
            if (isPressed)
            {
                if (onGround)
                {
                    dy = -310; 
                    jumpCount = 1; 
                }
                else if (jumpCount < 2) 
                {
                    dy = -310; 
                    jumpCount++;
                }
            }
            mIsMovingUp = isPressed;
        }
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
        if(life){
            if (mIsMovingUp && onGround)
            {
                dy = -310;
                onGround = false;
                doubleJumpAvailable = true; 
            }
            if (mIsMovingLeft)
            {
                movement.x -= PlayerSpeed.x;
                currentFrame += 0.005f * deltaTime.asMilliseconds();
                if (currentFrame > 2)
                    currentFrame -= 2;
                mPlayer.setTextureRect(sf::IntRect(35 * static_cast<int>(currentFrame)+35, 113, -35, 53)); 
            }
            if (mIsMovingRight)
            {
                movement.x += PlayerSpeed.x;
                currentFrame += 0.005f * deltaTime.asMilliseconds();
                if (currentFrame > 2)
                    currentFrame -= 2;
                mPlayer.setTextureRect(sf::IntRect(35 * static_cast<int>(currentFrame), 113, 35, 53)); 
            }
        
        
        dy += gravity;
        movement.y += dy;

        mPlayer.move(movement * deltaTime.asSeconds());

        if (mPlayer.getPosition().y + mPlayer.getGlobalBounds().height >= 2000)
        {
            mPlayer.setPosition(mPlayer.getPosition().x, 2000 - mPlayer.getGlobalBounds().height);
            dy = 0;
            onGround = true;
            doubleJumpAvailable = true;
            jumpCount = 0; 
        }
       
        CollisionX();
        CollisionY();


    }

        sf::View view = mWindow.getView();
 
        float halfScreenWidth = view.getSize().x / 2.f;
        float halfScreenHeight = view.getSize().y / 2.f;
        float x = mPlayer.getPosition().x;
        float y = mPlayer.getPosition().y - 100;

        if (x < halfScreenWidth) {
            x = halfScreenWidth;
        } else if (x > mapWidth * 30 - halfScreenWidth) {
            x = mapWidth * 30 - halfScreenWidth;
        }
        
        view.setCenter(x, y);
        mWindow.setView(view);

        if (health < 0) {life = false;}
}
    
    void Game::CollisionX()
    {
        int playerLeft = mPlayer.getPosition().x;
        int playerRight = playerLeft + mPlayer.getGlobalBounds().width;
        int playerTop = mPlayer.getPosition().y;
        int playerBottom = playerTop + mPlayer.getGlobalBounds().height;
    
        for (int i = playerTop / 30; i < playerBottom / 30; i++)
        {
            for (int j = playerLeft / 30; j < playerRight / 30; j++)
            {
                if (TileMap[i][j] == 'B')
                {
                    if (dx > 0) 
                    {
                        mPlayer.setPosition(j * 30 - mPlayer.getGlobalBounds().width, mPlayer.getPosition().y);
                        dx = 0;
                    }
                    else if (dx < 0) 
                    {
                        mPlayer.setPosition(j * 30 + 30, mPlayer.getPosition().y);
                        dx = 0;
                    }
                    
                }
                if (TileMap[i][j] == 'D') {
                    button.Reaction(); 
                    button.render(mWindow); 
                    TileMap[i][j] = ' '  ; 
                }   
                if (TileMap[i][j] == '8') {
                    health += 20;
                    TileMap[i][j] = ' '  ; 
                }   
                if (TileMap[i][j] == '9') {
                    health -= 20;
                    TileMap[i][j] = ' '  ; 
                } 
                
                if (TileMap[i][j] == 'A' && health <= 100) {
                    sf::Texture mFinalSlideTexture;
                    if (!mFinalSlideTexture.loadFromFile("./src/tileset/final.jpeg")) {
                        std::cerr << "Failed to load final slide texture!" << std::endl;
                    }
                    sf::Sprite finalSlideSprite(mFinalSlideTexture);
                    finalSlideSprite.setPosition(mPlayer.getPosition().x - 600, mPlayer.getPosition().y - 400);
                    finalSlideSprite.setScale(sf::Vector2f(1.f, 1.f));
                    mWindow.draw(finalSlideSprite);
                    mWindow.display();
                    sf::sleep(sf::seconds(5));
                    mWindow.close();
                }

            }
        }
        
        int tileIndex = (int)((playerRight - 1) / 30);
        int tileIndex1 = (int)(playerLeft / 30);
        int tileColumnIndex = (int)(playerTop / 30);
        if (TileMap[tileColumnIndex][tileIndex] == 'B')
        {
            mPlayer.setPosition(tileIndex * 30 - mPlayer.getGlobalBounds().width, mPlayer.getPosition().y);
            dx = 0;
        }
        if (TileMap[tileColumnIndex][tileIndex1] == 'B')
        {
           mPlayer.setPosition(mPlayer.getPosition().x, mPlayer.getPosition().y);
            dx = 0;
        }
    }
    
    
    void Game::CollisionY()
    {
        int playerLeft = mPlayer.getPosition().x;
        int playerRight = mPlayer.getPosition().x + mPlayer.getGlobalBounds().width;
        int playerTop = mPlayer.getPosition().y;
        int playerBottom = mPlayer.getPosition().y + mPlayer.getGlobalBounds().height;
    
        for (int i = playerTop / 30; i < playerBottom / 30; i++)
        {
            for (int j = playerLeft / 30; j < playerRight / 30; j++)
            {
                if (TileMap[i][j] == 'B')
                {
                    if (dy > 0) 
                    {
                        mPlayer.setPosition(mPlayer.getPosition().x, i * 30 - mPlayer.getGlobalBounds().height + 30);
                        dy = 0;
                        onGround = true;
                    }
                    else if (dy < 0) 
                    {
                        mPlayer.setPosition(mPlayer.getPosition().x, i * 30 + 30);
                        dy = 0;
                    }
                }
                if (TileMap[i][j] == 'D') {
                    button.Reaction();  
                    button.render(mWindow); 
                }   
            }
        }
    }



    void Game::InitSpriteMainCharacter()
    {
        if (!mTexture.loadFromFile("./src/jeff-the-killer2-PhotoRoom.png"))
            std::cout << "I can't connect the picture" << std::endl;
        mPlayer.setTexture(mTexture);
        rect = sf::FloatRect(0, 0, 40, 50);
        dx=dy=0;
        currentFrame = 0;
        onGround = true;
        mPlayer.setPosition(100.f, 100.f);
        mPlayer.setTextureRect(sf::IntRect(0, 113, 35, 53)); 
        health = 100;
        life = true;
    }

    void Game::initMap()
    {
        TileMap[0] =  "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
        TileMap[1] =  "B                             B         B";
        TileMap[2] =  "B                             B         B";
        TileMap[3] =  "B                             B         B";
        TileMap[4] =  "B                             B         B";
        TileMap[5] =  "B                             B         B";
        TileMap[6] =  "B                             B         B";
        TileMap[7] =  "B          D                            B";
        TileMap[8] =  "B          D                            B";
        TileMap[9] =  "B          BBBB    BBBBBBBB      BBBBBBBB";
        TileMap[10] = "B      BD                                B";
        TileMap[11] = "B  D   BBB         BBBBBBB            A  B";
        TileMap[12] = "B  D      BB                    BBBBBBBBBB";
        TileMap[13] = "BBBBB              99         BBBBB      B";
        TileMap[14] = "B         8999999999BBBBB        BBBBBB  B";
        TileMap[15] = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";     
    }

    void Game::drawMap(sf::RenderWindow& window)
    {

        if (!mTileTextureBound.loadFromFile("./src/tileset/Tile_3.png")) {
            std::cerr << "Failed to load tile texture!" << std::endl;
        }

        sf::Sprite tileSpriteBound(mTileTextureBound);


        if (!mTileTextureGround.loadFromFile("./src/tileset/Tile_14.png")) {
            std::cerr << "Failed to load tile texture!" << std::endl;
        }

        sf::Sprite tileSpriteGround(mTileTextureGround);
        
        if (!mTileTextureBox.loadFromFile("./src/tileset/Tile_16.png")) {
            std::cerr << "Failed to load tile texture!" << std::endl;
        }
        sf::Sprite mTileSpriteeBox(mTileTextureBox);
        
        if (!mTileTextureSkull.loadFromFile("./src/tileset/Tile_31.png")) {
            std::cerr << "Failed to load tile texture!" << std::endl;
        }
        sf::Sprite mTileSpriteSkull(mTileTextureSkull);
        
        if (!mTileTextureDoor.loadFromFile("./src/tileset/Tile_30.png")) {
            std::cerr << "Failed to load tile texture!" << std::endl;
        }
        sf::Sprite mTileSpriteDoor(mTileTextureDoor);

        tileSpriteBound.setScale(sf::Vector2f(0.2f, 0.2f));
        tileSpriteGround.setScale(sf::Vector2f(0.2f, 0.2f));
        mTileSpriteeBox.setScale(sf::Vector2f(0.2f, 0.2f));
        mTileSpriteSkull.setScale(sf::Vector2f(0.2f, 0.2f));
        mTileSpriteDoor.setScale(sf::Vector2f(0.2f, 0.2f));

        for (int i = 0; i < mapHeight; i++) {
            for (int j = 0; j < mapWidth; j++) {
                tileSpriteBound.setPosition(j * 30.f, i * 30.f); 
                tileSpriteGround.setPosition(j * 30.f, i * 30.f);
                mTileSpriteeBox.setPosition(j * 30.f, i * 30.f);
                mTileSpriteSkull.setPosition(j * 30.f, i * 30.f);
                mTileSpriteDoor.setPosition(j * 30.f, i * 30.f); 
                if (TileMap[i][j] == 'B') {
                    window.draw(tileSpriteBound);
                }
                if (TileMap[i][j] == 'D') {
                    button.render(mWindow,  j * 30, i * 30); 
                }
                if (TileMap[i][j] == '8') {
                    window.draw(mTileSpriteeBox);
                    
                }
                if (TileMap[i][j] == '9') {
                    window.draw(mTileSpriteSkull);
                }
                if (TileMap[i][j] == 'A') {
                    window.draw(mTileSpriteDoor);
                }

            }
        }
    }


    void Game::drawBackground(sf::RenderWindow& window) {
        if (!mBackgroundTexture.loadFromFile("./src/tileset/Background-1.png")) {
            std::cerr << "Failed to load background texture!" << std::endl;
        }
        mBackgroundSprite.setTexture(mBackgroundTexture); 
        mBackgroundSprite.setPosition(0, 0);
        mBackgroundSprite.setScale(sf::Vector2f(1.f, 1.f));
        window.draw(mBackgroundSprite);

    }


    void Game::render()
    {
        mWindow.clear(sf::Color(139, 69, 19));
        drawBackground(mWindow);
        drawMap(mWindow);
        mWindow.draw(mPlayer);  
        
        
        sf::Font font;
        if (!font.loadFromFile("./src/CyrilicOld.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
        }
        sf::Text healthText("Здоровье: " + std::to_string(health), font, 20);
        healthText.setFillColor(sf::Color::Black);
        healthText.setPosition(mPlayer.getPosition().x, mPlayer.getPosition().y - 50);
           
        
        sf::Text missionText("Завершите игру с нулевым счётом ", font, 20);
        missionText.setFillColor(sf::Color::Black);
        missionText.setPosition(50, 70);
            

        mWindow.draw(healthText);
        mWindow.draw(missionText);

        mWindow.display();
        sf::sleep(sf::milliseconds(33));
    }

    int main()
    {
        Game game;    
        game.run();
    }