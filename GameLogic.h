//
// Created by nicki on 06.05.2024.
//

#ifndef SOULKNIGHT_GAMELOGIC_H
#define SOULKNIGHT_GAMELOGIC_H
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "MiniMap.h"
#include "vector"

class GameLogic {
public:
    GameLogic();
    void update();
    void playerMove();
    void draw(sf::RenderWindow &window);
    void pressedKey(sf::Event event);
    void onCollision();
    void miniMapUpdate();
private:
    Map map;
    std::vector<Map> mapVector;
    MiniMap miniMap;
    std::vector<MiniMap> miniMapVec;


    Player player;
    bool isOnMap = true;

    sf::Texture greenTexture;
    sf::Texture redTexture;

};


#endif //SOULKNIGHT_GAMELOGIC_H
