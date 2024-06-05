//
// Created by nicki on 06.06.2024.
//

#include "Coin.h"

Coin::Coin() {
    if(!texture.loadFromFile("textures\\coin.png")){
        return;
    }

    sprite.setTexture(texture);
}

Coin::Coin(sf::Texture &texture, int x, int y) {
    if(!texture.loadFromFile("textures\\coin.png")){
        return;
    }
    sprite.setTexture(texture);

    sprite.setPosition(x,y);
}

void Coin::draw(sf::RenderWindow &window,std::vector<Coin> &coin) {
    for (int i = 0; i < coin.size(); ++i) {
        window.draw(coin[i].sprite);
    }
}

sf::Sprite *Coin::getSprite() {
    return &sprite;
}
