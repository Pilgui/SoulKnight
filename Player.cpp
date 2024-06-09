//
// Created by nicki on 06.05.2024.
//

#include "Player.h"
#include "Window.h"
#include "iostream"

Player::Player() : healthPoint(10) {
    speed = 5;
    damage = 1;

    if(!texture1.loadFromFile("textures\\player1.png")){
        return;
    }
    if(!texture2.loadFromFile("textures\\player2.png")){
        return;
    }
    if(!plDamagedTexture1.loadFromFile("textures\\playerDamaged1.png")){
        return;
    }
    if(!plDamagedTexture2.loadFromFile("textures\\playerDamaged2.png")){
        return;
    }
    sprite.setTexture(texture1);
//    sprite.setTextureRect(sf::IntRect (0,0,75,75));
    sprite.setPosition(Window::getWindowWidth()/2-24,Window::getWindowHeight()/2-75/2);

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

    if(!swordTexture.loadFromFile("textures\\swordIcon.png")){
        return;
    }
    swordSprite.setTexture(swordTexture);
    swordSprite.setPosition(Window::getWindowWidth()-100,90);

    swordText.setFont(font);
    swordText.setFillColor(sf::Color::Black);
    swordText.setPosition(Window::getWindowWidth()-50,90);

}


void Player::update() {
    hpText.setString(std::to_string(healthPoint));
    coinText.setString(std::to_string(coinScore));
    swordText.setString(std::to_string(damage));
    if (isDamaged && damageClock.getElapsedTime().asSeconds() > 0.1) {
        resetTexture();
    }
//    std::cout << isDamaged;
    if (!isDamaged) {
        if (movingRight) {
            sprite.setTexture(texture1);
        } else if (movingLeft) {
            sprite.setTexture(texture2);
        }
    }
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(spriteHeart);
    window.draw(hpText);
    window.draw(coinSprite);
    window.draw(coinText);
    window.draw(swordSprite);
    window.draw(swordText);
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

void Player::setDamage(int d) {
    damage = d;
}

int Player::getDamage() {
    return damage;
}

void Player::getDamaged() {
    if (sprite.getTexture() == &texture1) {
        sprite.setTexture(plDamagedTexture1);
    } else if (sprite.getTexture() == &texture2) {
        sprite.setTexture(plDamagedTexture2);
    }
    isDamaged = true;
    damageClock.restart();
}

void Player::resetTexture() {
    if (movingRight) {
        sprite.setTexture(texture1);
    } else if (movingLeft) {
        sprite.setTexture(texture2);
    }
    isDamaged = false;
}



