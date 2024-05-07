//
// Created by nicki on 06.05.2024.
//

#ifndef SOULKNIGHT_GAMELOGIC_H
#define SOULKNIGHT_GAMELOGIC_H
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "vector"

class GameLogic {
public:
    GameLogic();
    void playerMove();
    void draw(sf::RenderWindow &window);
private:
    Map map;
    std::vector<Map> mapVector;

    Player player;
};


#endif //SOULKNIGHT_GAMELOGIC_H
