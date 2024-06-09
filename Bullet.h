//
// Created by nicki on 24.05.2024.
//

#ifndef SOULKNIGHT_BULLET_H
#define SOULKNIGHT_BULLET_H
#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet();
    Bullet(float x, float y, float angle);
    void draw(sf::RenderWindow &window);
    void update(std::vector<Bullet> &bulletVec);
    void setSpeed(float fSpeed);
    float getSpeed();
    sf::CircleShape *getSprite();
private:
    sf::CircleShape circleShape;

    float speed = 7;
    float velocityX;
    float velocityY;

};


#endif //SOULKNIGHT_BULLET_H
