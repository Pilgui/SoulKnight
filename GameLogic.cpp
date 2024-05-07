//
// Created by nicki on 06.05.2024.
//

#include "GameLogic.h"

GameLogic::GameLogic() {
    map.start(mapVector);
}

void GameLogic::playerMove()
{
    map.move(mapVector,player);
}

void GameLogic::draw(sf::RenderWindow &window) {
    map.draw(window,mapVector);
    player.draw(window);
}
