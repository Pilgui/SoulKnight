//
// Created by nicki on 06.05.2024.
//

#include "GameLogic.h"
#include "iostream"
GameLogic::GameLogic(): gun(Gun(player)) {
    map.start(mapVector,miniMapVec);
    if(!redTexture.loadFromFile("textures\\red.png")){
        return;
    }
    if(!greenTexture.loadFromFile("textures\\texture.png")){
        return;
    }
}
void GameLogic::update(sf::RenderWindow &window){
    miniMapUpdate();
    playerMove();
    spawnEnemies();
    onCollision();
    player.update();
    gun.update(window);
    enemy.update(enemyVec,player,coinVec,scoreEnemy);
}

void GameLogic::playerMove()
{
    if (player.movingRight && player.isRightBorder) {
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].getSprite()->move(-player.getSpeed(), 0);
        }
        for (int i = 0; i < enemyVec.size(); ++i) {
            enemyVec[i].getSprite()->move(-player.getSpeed(),0);
        }
        for (int i = 0; i < coinVec.size(); ++i) {
            coinVec[i].getSprite()->move(-player.getSpeed(),0);
        }
    }
    if (player.movingLeft && player.isLeftBorder) {
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].getSprite()->move(player.getSpeed(), 0);
        }
        for (int i = 0; i < enemyVec.size(); ++i) {
            enemyVec[i].getSprite()->move(player.getSpeed(),0);
        }
        for (int i = 0; i < coinVec.size(); ++i) {
            coinVec[i].getSprite()->move(player.getSpeed(),0);
        }
    }
    if (player.movingUp && player.isTopBorder) {
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].getSprite()->move(0, player.getSpeed());
        }for (int i = 0; i < enemyVec.size(); ++i) {
            enemyVec[i].getSprite()->move(0,player.getSpeed());
        }
        for (int i = 0; i < coinVec.size(); ++i) {
            coinVec[i].getSprite()->move(0,player.getSpeed());
        }
    }
    if (player.movingDown && player.isBottomBorder) {
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].getSprite()->move(0, -player.getSpeed());
        }for (int i = 0; i < enemyVec.size(); ++i) {
            enemyVec[i].getSprite()->move(0,-player.getSpeed());
        }
        for (int i = 0; i < coinVec.size(); ++i) {
            coinVec[i].getSprite()->move(0,-player.getSpeed());
        }
    }
}

void GameLogic::draw(sf::RenderWindow &window) {
    map.draw(window,mapVector);
    miniMap.draw(window,miniMapVec);
    player.draw(window);
    gun.draw(window);
    enemy.draw(window,enemyVec);
    coin.draw(window,coinVec);
}

void GameLogic::keyEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        pressedKey(event.key.code, true);
    }
    if (event.type == sf::Event::KeyReleased) {
        pressedKey(event.key.code, false);
    }
    gun.shoot();
}
void GameLogic::pressedKey(sf::Keyboard::Key &key, bool isPressed) {
    switch (key) {
        case sf::Keyboard::Key::Right:
            player.movingRight = isPressed;
            break;
        case sf::Keyboard::Key::Left:
            player.movingLeft = isPressed;
            break;
        case sf::Keyboard::Key::Up:
            player.movingUp = isPressed;
            break;
        case sf::Keyboard::Key::Down:
            player.movingDown = isPressed;
            break;
        default:
            break;
    }
}

void GameLogic::onCollision() {
    for (int i = 0; i < mapVector.size(); i++) {
        sf::FloatRect playerBounds = player.getSprite()->getGlobalBounds();
        sf::FloatRect mapBounds = mapVector[i].getSprite()->getGlobalBounds();
        sf::FloatRect tunnelMapBounds = mapVector[i+1].getSprite()->getGlobalBounds();

        if (playerBounds.intersects(mapBounds) && (i % 2 == 0 || i == 0)) {

            float playerRight = playerBounds.left + playerBounds.width;
            float playerBottom = playerBounds.top + playerBounds.height;
            float mapRight = mapBounds.left + mapBounds.width;
            float mapBottom = mapBounds.top + mapBounds.height;
            float tunnelRight = tunnelMapBounds.left + tunnelMapBounds.width;
            float tunnelBottom = tunnelMapBounds.top + tunnelMapBounds.height;

            if (playerBounds.left < mapBounds.left && playerRight > mapBounds.left) {
                player.isLeftBorder = false;
            } else if ((playerRight > mapRight && playerBounds.left < mapRight)) {
                if((playerBounds.left > tunnelMapBounds.left && playerRight < tunnelMapBounds.left) &&
                        (playerBottom > tunnelBottom && playerBounds.top < tunnelMapBounds.top)){
                    std::cout << "RRRR" << std::endl;
                    player.isRightBorder = false;
                }
            } else if(false){

            } else if (playerBounds.top < mapBounds.top && playerBottom > mapBounds.top) {
                player.isTopBorder = false;
            } else if (playerBottom > mapBottom && playerBounds.top < mapBottom) {
                player.isBottomBorder = false;
            }else {
                player.isBottomBorder = true;
                player.isTopBorder = true;
                player.isLeftBorder = true;
                player.isRightBorder = true;
            }
        }
    }
    elapsedTime += clock.restart();
    for (int i = 0; i < enemyVec.size(); ++i) {
        if(player.getSprite()->getGlobalBounds().intersects(enemyVec[i].getSprite()->getGlobalBounds()) &&
            elapsedTime > sf::seconds(1)){
            player.setHP(player.getHP()-1);
            elapsedTime = sf::Time::Zero;
        }
        for (int j = 0; j < gun.getBulletVec()->size(); ++j) {
            if (enemyVec[i].getSprite()->getGlobalBounds().intersects(gun.getBulletVec()->at(j).getSprite()->getGlobalBounds())) {
                auto bulletIter = gun.getBulletVec()->begin() + j;
                gun.getBulletVec()->erase(bulletIter);
                enemyVec[i].setHP(enemyVec[i].getHP() - 1);
                break;
            }
        }
    }
    for (int i = 0; i < coinVec.size(); ++i) {
        if (player.getSprite()->getGlobalBounds().intersects(coinVec[i].getSprite()->getGlobalBounds())) {
            auto iter = coinVec.begin() + i;
            coinVec.erase(iter);
            player.setCoinScore(player.getCoinScore()+1);
        }
    }
}

void GameLogic::miniMapUpdate() {
    for (int i = 0; i < mapVector.size(); ++i) {
        bool isIntersecting = player.getSprite()->getGlobalBounds().intersects(mapVector[i].getSprite()->getGlobalBounds());

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

void GameLogic::spawnEnemies() {
    enemyVec.reserve(3);
    for (int i = 0; i < mapVector.size(); ++i) {
        if(player.getSprite()->getGlobalBounds().intersects(mapVector[i].getSprite()->getGlobalBounds())){
            if(mapVector[i].typeRoom == map.ENEMY){
                inEnemyRoom = true;
            }else if(mapVector[i].typeRoom == map.TUNNEL || mapVector[i].typeRoom == map.SPAWN){
                scoreEnemy = 0;
                inEnemyRoom = false;
            }
        }
    }

    while (enemyVec.size() < 3 && inEnemyRoom && scoreEnemy <= 7) {
        for (int i = 0; i < mapVector.size(); ++i) {
            if (mapVector[i].typeRoom == map.ENEMY &&
                player.getSprite()->getGlobalBounds().intersects(mapVector[i].getSprite()->getGlobalBounds())) {
                int randNumX = (rand() % 850) + 1;
                int randNumY = (rand() % 850) + 1;
                enemyVec.emplace_back(redTexture, mapVector[i].getSprite()->getPosition().x + randNumX,
                                          mapVector[i].getSprite()->getPosition().y + randNumY);
//                std::cout << i << "ENEMY" << std::endl;
            }
        }
    }
}


