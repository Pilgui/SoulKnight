//
// Created by nicki on 06.05.2024.
//

#include "Player.h"
#include "Window.h"

Player::Player() {
    speed = 5;

    if(!texture.loadFromFile("textures\\blue.png")){
        return;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (0,0,75,75));
    sprite.setPosition(Window::getWindowWidth()/2,Window::getWindowHeight()/2);
}

float Player::getSpeed() {
    return speed;
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Player::setSpeed(float speedF) {
    speedF = speed;
}
