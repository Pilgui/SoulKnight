//
// Created by nicki on 06.06.2024.
//

#include "Shop.h"
#include "iostream"
#include "Window.h"

Shop::Shop() {
    if(!texture.loadFromFile("textures\\store.png")){
        return;
    }
    sprite.setTexture(texture);
//    sprite.setTextureRect(sf::IntRect (0,0,200,200));

    if(!shopScreenTexture.loadFromFile("textures\\shopScreen.png")){
        return;
    }
    if(!iconDamageUpgradeTexture.loadFromFile("textures\\sword.png")){
        return;
    }
    if(!iconHPUpgradeTexture.loadFromFile("textures\\heartIcon.png")){
        return;
    }
    if(!iconUpgradeTexture1.loadFromFile("textures\\upgradeIcon.png")){
        return;
    }if(!iconUpgradeTexture2.loadFromFile("textures\\upgradeIcon.png")){
        return;
    }

    iconUpgrade1.setTexture(iconUpgradeTexture1);
    iconUpgrade2.setTexture(iconUpgradeTexture2);
    iconHPUpgrade.setTexture(iconHPUpgradeTexture);
    iconDamageUpgrade.setTexture(iconDamageUpgradeTexture);
    shopScreen.setTexture(shopScreenTexture);
    shopScreen.setTextureRect(sf::IntRect (0,0,500,500));

    shopScreen.setPosition(Window::getWindowWidth()/2-250,Window::getWindowWidth()/2-250);
    iconHPUpgrade.setPosition(shopScreen.getPosition().x + 150,shopScreen.getPosition().y + 150);
    iconDamageUpgrade.setPosition(shopScreen.getPosition().x + 300,shopScreen.getPosition().y + 150);
    iconUpgrade1.setPosition(shopScreen.getPosition().x + 150,shopScreen.getPosition().y + 250);
    iconUpgrade2.setPosition(shopScreen.getPosition().x + 300,shopScreen.getPosition().y + 250);
}

void Shop::start(std::vector<Map> &mapVec) {
    sprite.setPosition(mapVec[4].getSprite()->getPosition().x+450-250,mapVec[4].getSprite()->getPosition().y+450-250);
}

void Shop::update(std::vector<Map> &mapVec, sf::RenderWindow &window, Player &player) {
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
    if(sprite.getGlobalBounds().contains(mousePos)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                player.getSprite()->getGlobalBounds().intersects(sprite.getGlobalBounds())){
            isShopOpen = true;
            std::cout<<1;
        }
    }
    if(!player.getSprite()->getGlobalBounds().intersects(sprite.getGlobalBounds())){
        isShopOpen = false;
    }

    elapsedTime += clock.restart();

    if (player.getSprite()->getGlobalBounds().intersects(sprite.getGlobalBounds())) {
        if (iconUpgrade1.getGlobalBounds().contains(mousePos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                elapsedTime > sf::seconds(1)) {
                if (player.getCoinScore() >= 5) {
                    player.setHP(player.getHP() + 5);
                    player.setCoinScore(player.getCoinScore() - 5);
                    elapsedTime = sf::Time::Zero;
                }
            }
        }
        if (iconUpgrade2.getGlobalBounds().contains(mousePos)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                elapsedTime > sf::seconds(1)) {
                if (player.getCoinScore() >= 5) {
                    player.setDamage(player.getDamage() + 1);
                    player.setCoinScore(player.getCoinScore() - 5);
                    elapsedTime = sf::Time::Zero;
                }
            }
        }
    }
}

void Shop::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    if(isShopOpen){
        drawShop(window);
    }
}

sf::Sprite *Shop::getSprite() {
    return &sprite;
}


void Shop::drawShop(sf::RenderWindow &window) {
    window.draw(shopScreen);
    window.draw(iconUpgrade1);
    window.draw(iconUpgrade2);
    window.draw(iconHPUpgrade);
    window.draw(iconDamageUpgrade);
}
