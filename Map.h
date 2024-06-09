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
    void draw(sf::RenderWindow &window, std::vector<Map> &mapVector);
    sf::Sprite *getSprite();
    void backGroundMoves(Player &player);

    enum typeRoom{
        ENEMY,
        SHOP,
        SPAWN,
        TUNNEL
    };
    typeRoom typeRoom;

private:
    sf::Sprite sprite;
    sf::Texture mapTexture;
    sf::Texture tunnelTexture1;
    sf::Texture tunnelTexture2;
    sf::Texture miniMapTexture;
    sf::Texture miniTunnelTexture1;
    sf::Texture miniTunnelTexture2;

    MiniMap miniMap;
    int sizeW;
    int sizeH;

    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    std::vector<sf::Sprite> backgroundVec;


};


#endif //SOULKNIGHT_MAP_H
