//
// Created by nicki on 06.05.2024.
//

#include "Player.h"
#include "Window.h"

Player::Player() : healthPoint(10) {
    speed = 5;

    if(!texture.loadFromFile("textures\\blue.png")){
        return;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (0,0,75,75));
    sprite.setPosition(Window::getWindowWidth()/2-75,Window::getWindowHeight()/2-75);

    if(!textureHeart.loadFromFile("textures\\heart.png")){
        return;
    }
    spriteHeart.setTexture(textureHeart);
    spriteHeart.setPosition(Window::getWindowWidth()-100,0);

}

float Player::getSpeed() {
    return speed;
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(spriteHeart);
}

sf::Sprite Player::getSprite() {
    return sprite;
}

float Player::getPositionX() {
    return sprite.getPosition().x;
}

float Player::getPositionY() {
    return sprite.getPosition().y;
}


