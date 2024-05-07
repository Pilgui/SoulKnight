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
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float speed;
};


#endif //SOULKNIGHT_PLAYER_H
