//
// Created by nicki on 06.05.2024.
//

#include "GameLogic.h"
#include "iostream"
GameLogic::GameLogic() {
    map.start(mapVector,miniMapVec);
    if(!redTexture.loadFromFile("textures\\red.png")){
        return;
    }
    if(!greenTexture.loadFromFile("textures\\texture.png")){
        return;
    }
}

void GameLogic::playerMove()
{
    if(isOnMap) {
        map.move(mapVector, player);
    }
}

void GameLogic::draw(sf::RenderWindow &window) {
    map.draw(window,mapVector);
    miniMap.draw(window,miniMapVec);
    player.draw(window);
}

void GameLogic::pressedKey(sf::Event event) {
    if (isOnMap) {
        if (event.type == sf::Event::KeyPressed) {
            map.pressedKey(player, event.key.code, true);
        }
        if (event.type == sf::Event::KeyReleased) {
            map.pressedKey(player, event.key.code, false);
        }
    }
}

void GameLogic::onCollision() {
    /*for (int i = 0; i < mapVector.size(); ++i) {
        if (player.getSprite().getGlobalBounds().intersects(mapVector[i].getSprite().getGlobalBounds())) {
            isOnMap = true;
            return;
        } else {
            isOnMap = false;
            return;
        }
    }*/
    for (int i = 0;i < mapVector.size();i++) {
        sf::FloatRect playerBounds = player.getSprite().getGlobalBounds();
        sf::FloatRect mapBounds = mapVector[i].getSprite().getGlobalBounds();

        if (playerBounds.left == mapBounds.left) {
            player.movingLeft = false;
        }
        if (playerBounds.left + playerBounds.width == mapBounds.left + mapBounds.width) {
            player.movingRight = false;
        }
        if (playerBounds.top == mapBounds.top) {
            player.movingUp = false;
        }
        if (playerBounds.top + playerBounds.height == mapBounds.top + mapBounds.height) {
            player.movingDown = false;
        }
    }
}

void GameLogic::miniMapUpdate() {
    for (int i = 0; i < mapVector.size(); ++i) {
        bool isIntersecting = player.getSprite().getGlobalBounds().intersects(mapVector[i].getSprite().getGlobalBounds());

        if (isIntersecting) {
            if (miniMapVec[i].getTypeRoom() == 1) {
                miniMapVec[i].getSpite()->setTexture(redTexture);
            } else if (miniMapVec[i].getTypeRoom() == 2) {
                miniMapVec[i].getSpite()->setTexture(greenTexture);
            }
        } else {
            if (miniMapVec[i].getTypeRoom() == 1) {
                miniMapVec[i].getSpite()->setTexture(greenTexture);
            }
        }
    }
}

void GameLogic::update() {
    miniMapUpdate();
    playerMove();
    onCollision();
}
