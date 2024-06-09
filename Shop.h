//
// Created by nicki on 06.06.2024.
//

#ifndef SOULKNIGHT_SHOP_H
#define SOULKNIGHT_SHOP_H
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
class Shop {
public:
    Shop();
    void start(std::vector<Map> &mapVec);
    void update(std::vector<Map> &mapVec, sf::RenderWindow &window , Player &player);
    void drawShop(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    sf::Sprite *getSprite();
private:
    sf::Texture texture;
    sf::Sprite sprite;

    bool isShopOpen = false;

    sf::Sprite shopScreen;
    sf::Sprite iconHPUpgrade;;
    sf::Sprite iconDamageUpgrade;
    sf::Sprite iconUpgrade1;
    sf::Sprite iconUpgrade2;

    sf::Texture shopScreenTexture;
    sf::Texture iconHPUpgradeTexture;
    sf::Texture iconDamageUpgradeTexture;
    sf::Texture iconUpgradeTexture1;
    sf::Texture iconUpgradeTexture2;
    sf::Time elapsedTime;
    sf::Clock clock;
};


#endif //SOULKNIGHT_SHOP_H
