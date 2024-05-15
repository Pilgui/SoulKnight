//
// Created by nicki on 07.05.2024.
//

#ifndef SOULKNIGHT_MAP_H
#define SOULKNIGHT_MAP_H
#include<SFML/Graphics.hpp>
#include "Player.h"
#include "MiniMap.h"
#include <vector>

class Map {
public:
    Map();
    Map(sf::Texture &texture, int x, int y, int sizeW, int sizeH);
    void start(std::vector<Map> &mapVector,std::vector<MiniMap> &miniMapVec);
    void move(std::vector<Map> &mapVector,Player &player);
    void draw(sf::RenderWindow &window, std::vector<Map> &mapVector);
    void pressedKey(Player &player, sf::Keyboard::Key key, bool isPressed);
    sf::Sprite getSprite();
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Texture textureSpawn;

    MiniMap miniMap;
    int sizeW;
    int sizeH;
};


#endif //SOULKNIGHT_MAP_H
