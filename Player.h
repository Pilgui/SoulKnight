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
    float getSpeed();
    sf::Sprite getSprite();

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

private:
    sf::Sprite sprite;
    sf::Texture texture;

    int healthPoint;
    sf::Texture textureHeart;
    sf::Sprite spriteHeart;
    sf::Text hpText;

    float speed;
};


#endif //SOULKNIGHT_PLAYER_H
