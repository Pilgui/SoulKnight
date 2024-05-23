//
// Created by nicki on 23.05.2024.
//

#ifndef SOULKNIGHT_GUN_H
#define SOULKNIGHT_GUN_H
#include <SFML/Graphics.hpp>

class Gun {
public:
    Gun();
    void draw(sf::RenderWindow &window);
private:
    sf::Sprite sprite;
    sf::Texture texture;
};


#endif //SOULKNIGHT_GUN_H
