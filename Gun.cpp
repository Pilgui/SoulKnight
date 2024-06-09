//
// Created by nicki on 23.05.2024.
//

#include "Gun.h"
#include "Window.h"
#include "cmath"
#include "iostream"

Gun::Gun(Player &player) {
    if(!texture.loadFromFile("textures\\gun.png")){
        return;
    }
    if(!texture2.loadFromFile("textures\\gun2.png")){
        return;
    }
    sprite.setTexture(texture);

    sprite.setPosition(player.getPositionX()+23,player.getPositionY()+65);
    sprite.setOrigin(0, sprite.getLocalBounds().height);
    bulletVec.reserve(3);
}

void Gun::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    for (int i = 0; i < bulletVec.size(); ++i) {
        window.draw(*bulletVec[i].getSprite());
    }
}

void Gun::update(sf::RenderWindow &window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f spritePosition = sprite.getPosition();
    float dx = mousePosition.x - spritePosition.x;
    float dy = mousePosition.y - spritePosition.y;
    angle = std::atan2(dy,dx) * 180 / M_PI;

    sprite.setRotation(angle);

    if (dx < 0) {
        sprite.setTexture(texture2);
        sprite.setOrigin(sprite.getLocalBounds().width, sprite.getLocalBounds().height);
        sprite.setRotation(angle + 180); // Корректируем угол поворота
    } else {
        sprite.setTexture(texture);
        sprite.setOrigin(0, sprite.getLocalBounds().height);
        sprite.setRotation(angle);
    }

    if (isShooting) {
        bullet.update(bulletVec);
    }
    for (int i = 0; i < bulletVec.size(); ++i) {
        if((bulletVec[i].getSprite()->getPosition().x > Window::getWindowWidth() || bulletVec[i].getSprite()->getPosition().x < 0) ||
           (bulletVec[i].getSprite()->getPosition().y > Window::getWindowHeight() || bulletVec[i].getSprite()->getPosition().y < 0)){
            auto iter = bulletVec.begin() + i;
            bulletVec.erase(iter);
        }
    }
}

void Gun::shoot() {

    sf::Time elapsed = clock.getElapsedTime();

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && elapsed - lastShootTime >= sf::seconds(0.1) ){
        sf::Vector2f endPos = getEndPos();
        bulletVec.emplace_back(Bullet(endPos.x,endPos.y,angle));
        isShooting = true;
        lastShootTime = elapsed;
    }
}

sf::Vector2f Gun::getEndPos() {
    sf::Transform transform;
    transform.rotate(sprite.getRotation(), sprite.getOrigin());
    sf::Vector2f endPos;

    if (sprite.getTexture() == &texture2) {
        endPos = transform.transformPoint(sprite.getOrigin().x - sprite.getLocalBounds().width, sprite.getLocalBounds().height / 2);
    } else {
        endPos = transform.transformPoint(sprite.getLocalBounds().width, sprite.getLocalBounds().height / 2);
    }

    endPos += sprite.getPosition() - sprite.getOrigin();
    return endPos;
}

std::vector<Bullet> *Gun::getBulletVec() {
    return &bulletVec;
}
