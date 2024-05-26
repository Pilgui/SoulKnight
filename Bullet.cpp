//
// Created by nicki on 24.05.2024.
//

#include "Bullet.h"
#include "Window.h"
#include "iostream"
#include "cmath"

Bullet::Bullet() {
    circleShape.setRadius(7);
    circleShape.setPosition(Window::getWindowWidth()/2,Window::getWindowHeight()/2);
    circleShape.setFillColor(sf::Color::Yellow);
}

Bullet::Bullet(float x, float y, float angle) {
    circleShape.setRadius(7);
    circleShape.setFillColor(sf::Color::Yellow);
    circleShape.setPosition(x,y);

    float radians = angle * M_PI / 180.0f;
    velocityX = std::cos(radians) * speed;
    velocityY = std::sin(radians) * speed;
}

void Bullet::draw(sf::RenderWindow &window) {
    window.draw(circleShape);
}

void Bullet::update(std::vector<Bullet> &bulletVec) {
    for (int i = 0; i < bulletVec.size(); ++i) {
        bulletVec[i].circleShape.move(bulletVec[i].velocityX,bulletVec[i].velocityY);
    }
}

void Bullet::setSpeed(float fSpeed) {
    speed = fSpeed;
}

float Bullet::getSpeed() {
   return speed;
}

sf::CircleShape *Bullet::getSprite() {
    return &circleShape;
}


