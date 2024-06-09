//
// Created by nicki on 28.05.2024.
//

#ifndef SOULKNIGHT_ENEMY_H
#define SOULKNIGHT_ENEMY_H
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "vector"
#include "Coin.h"


class Enemy {
public:
    Enemy();
    Enemy(sf::Texture &texture,int x,int y);
    void draw(sf::RenderWindow &window,std::vector<Enemy> &enemyVec);
    void update(std::vector<Enemy> &enemyVec, Player &player,std::vector<Coin> &coinVec, int &scoreEnemy);
    sf::Sprite *getSprite();
    sf::Texture *getTexture();
    int getHP();
    void setHP(int HP);
    void setDamageTexture(sf::Texture &texture);
    void setNormalTexture(sf::Texture &texture);
    void updateState();
    sf::Clock damageClock;
    bool isDamaged = false;
private:
    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;

    int healthPoint;

    sf::Sprite sprite;
    sf::Texture texture;

    sf::Texture coinTexture;

    float enemySpeed = 5;
    bool isDead = false;
    char way;


    sf::Texture *normalTexture;

    float damageTime = 0.1f;
};


#endif //SOULKNIGHT_ENEMY_H
