//
// Created by nicki on 06.05.2024.
//

#ifndef SOULKNIGHT_GAMELOGIC_H
#define SOULKNIGHT_GAMELOGIC_H
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "MiniMap.h"
#include "vector"
#include "Gun.h"


class GameLogic {
public:
    GameLogic();
    void update(sf::RenderWindow &window);
    void playerMove();
    void draw(sf::RenderWindow &window);
    void keyEvent(sf::Event &event);
    void pressedKey(sf::Keyboard::Key &key, bool isPressed);
    void onCollision();
    void miniMapUpdate();
private:
    Map map;
    std::vector<Map> mapVector;

    MiniMap miniMap;
    std::vector<MiniMap> miniMapVec;


    Player player;
    Gun gun;

    sf::Texture greenTexture;
    sf::Texture redTexture;

};


#endif //SOULKNIGHT_GAMELOGIC_H
