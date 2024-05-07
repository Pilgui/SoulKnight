//
// Created by nicki on 07.05.2024.
//

#ifndef SOULKNIGHT_MAP_H
#define SOULKNIGHT_MAP_H
#include<SFML/Graphics.hpp>
#include "Player.h"
#include <vector>

class Map {
public:
    Map();
    Map(sf::Texture &texture);
    void start(std::vector<Map> &mapVector);
    void move(std::vector<Map> &mapVector,Player &player);
    void draw(sf::RenderWindow &window, std::vector<Map> &mapVector);
private:
    sf::Sprite sprite;
    sf::Texture texture;
};


#endif //SOULKNIGHT_MAP_H
