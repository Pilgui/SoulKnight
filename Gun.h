//
// Created by nicki on 23.05.2024.
//

#ifndef SOULKNIGHT_GUN_H
#define SOULKNIGHT_GUN_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"

class Gun {
public:
    Gun(Player &player);
    void draw(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void shoot();
    sf::Vector2f getEndPos();
private:
    sf::Clock clock;
    sf::Time lastShootTime = sf::Time::Zero;

    sf::Sprite sprite;
    sf::Texture texture;

    Bullet bullet;
    std::vector<Bullet> bulletVec;
    bool isShooting = false;
    float angle;
};


#endif //SOULKNIGHT_GUN_H
