//
// Created by nicki on 06.06.2024.
//

#ifndef SOULKNIGHT_COIN_H
#define SOULKNIGHT_COIN_H
#include "SFML/Graphics.hpp"

class Coin {
public:
    Coin();
    Coin(sf::Texture &texture,int x, int y);
    void draw(sf::RenderWindow &window,std::vector<Coin> &coin);
    sf::Sprite *getSprite();
private:
    sf::Sprite sprite;
    sf::Texture texture;
};


#endif //SOULKNIGHT_COIN_H
