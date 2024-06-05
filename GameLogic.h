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
#include "Enemy.h"


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
    void spawnEnemies();
private:
    Map map;
    std::vector<Map> mapVector;

    MiniMap miniMap;
    std::vector<MiniMap> miniMapVec;

    Enemy enemy;
    std::vector<Enemy> enemyVec;

    Player player;
    Gun gun;

    Coin coin;
    std::vector<Coin> coinVec;

    sf::Texture greenTexture;
    sf::Texture redTexture;


    bool inEnemyRoom = false;

    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;

    int scoreEnemy = 0;
};


#endif //SOULKNIGHT_GAMELOGIC_H
