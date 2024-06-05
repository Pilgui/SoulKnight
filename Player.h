//
// Created by nicki on 06.05.2024.
//

#ifndef SOULKNIGHT_PLAYER_H
#define SOULKNIGHT_PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void draw(sf::RenderWindow &window);
    void update();

    float getSpeed();
    sf::Sprite *getSprite();

    bool movingRight = false;
    bool movingLeft = false;
    bool movingUp = false;
    bool movingDown = false;

    bool isTopBorder = true;
    bool isBottomBorder = true;
    bool isLeftBorder = true;
    bool isRightBorder = true;

    float getPositionX();
    float getPositionY();

    void setHP(int hp);
    int getHP();

    void setCoinScore(int cs);
    int getCoinScore();

private:
    sf::Sprite sprite;
    sf::Texture texture;

    int healthPoint;
    int coinScore = 0;

    sf::Texture textureHeart;
    sf::Sprite spriteHeart;

    sf::Text hpText;
    sf::Font font;

    sf::Sprite coinSprite;
    sf::Texture coinTexture;
    sf::Text coinText;


    float speed;
};


#endif //SOULKNIGHT_PLAYER_H
