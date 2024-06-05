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

    if(!font.loadFromFile("fonts\\font.ttf")){
        return;
    }
    hpText.setFont(font);
    hpText.setFillColor(sf::Color::Black);
    hpText.setPosition(Window::getWindowWidth()-50,0);

    if(!coinTexture.loadFromFile("textures\\coinIcon.png")){
        return;
    }
    coinSprite.setTexture(coinTexture);
    coinSprite.setPosition(Window::getWindowWidth()-100,45);

    coinText.setFont(font);
    coinText.setFillColor(sf::Color::Black);
    coinText.setPosition(Window::getWindowWidth()-50,45);

}


void Player::update() {
    hpText.setString(std::to_string(healthPoint));
    coinText.setString(std::to_string(coinScore));
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(spriteHeart);
    window.draw(hpText);
    window.draw(coinSprite);
    window.draw(coinText);
}

sf::Sprite *Player::getSprite() {
    return &sprite;
}

float Player::getPositionX() {
    return sprite.getPosition().x;
}

float Player::getPositionY() {
    return sprite.getPosition().y;
}
float Player::getSpeed() {
    return speed;
}

void Player::setHP(int hp) {
    healthPoint = hp;
}

int Player::getHP() {
    return healthPoint;
}

void Player::setCoinScore(int cs) {
    coinScore = cs;
}

int Player::getCoinScore() {
    return coinScore;
}



