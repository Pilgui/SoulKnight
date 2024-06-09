//
// Created by nicki on 28.05.2024.
//

#include "Enemy.h"
#include "iostream"
#include "cmath"


Enemy::Enemy() {
    if(!texture.loadFromFile("textures\\enemy.png")){
        return;
    }
    if(!coinTexture.loadFromFile("textures\\coin.png")){
        return;
    }

    sprite.setTexture(texture);
    normalTexture = &texture;
}

Enemy::Enemy(sf::Texture &texture,int x, int y) : healthPoint(3){
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
    normalTexture = &texture;
}

void Enemy::draw(sf::RenderWindow &window, std::vector<Enemy> &enemyVec) {
    for (int i = 0; i < enemyVec.size(); ++i) {
        window.draw(enemyVec[i].sprite);
    }
}

sf::Sprite *Enemy::getSprite() {
    return &sprite;
}

void Enemy::update(std::vector<Enemy> &enemyVec,Player &player,std::vector<Coin> &coinVec, int &scoreEnemy) {

    float playerX = player.getSprite()->getPosition().x;
    float playerY = player.getSprite()->getPosition().y;

    for (int i = 0; i < enemyVec.size(); ++i) {
        float enemyX = enemyVec[i].getSprite()->getPosition().x;
        float enemyY = enemyVec[i].getSprite()->getPosition().y;

        // Calculate the direction vector
        float dirX = playerX - enemyX;
        float dirY = playerY - enemyY;

        // Normalize the direction vector
        float length = sqrt(dirX * dirX + dirY * dirY);
        if (length != 0) {
            dirX /= length;
            dirY /= length;
        }

        // Move the enemy towards the player
        float enemySpeed = 1.0f; // Adjust the speed as needed
        enemyVec[i].sprite.move(dirX * enemySpeed, dirY * enemySpeed);

        if(enemyVec[i].healthPoint <= 0){
            scoreEnemy++;
            coinVec.emplace_back(Coin(coinTexture,enemyVec[i].sprite.getPosition().x+25,enemyVec[i].sprite.getPosition().y+25));
            enemyVec[i].isDead = true;

            auto iter = enemyVec.begin() + i;
            enemyVec.erase(iter);
        }
    }
}

sf::Texture *Enemy::getTexture() {
    return &texture;
}

int Enemy::getHP() {
    return healthPoint;
}

void Enemy::setHP(int HP) {
    healthPoint = HP;
}

void Enemy::updateState() {
    if (isDamaged) {
        if (damageClock.getElapsedTime().asSeconds() > damageTime) {
            sprite.setTexture(*normalTexture);
            isDamaged = false;
        }
    }
}

