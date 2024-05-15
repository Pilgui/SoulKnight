//
// Created by nicki on 13.05.2024.
//

#include "MiniMap.h"

MiniMap::MiniMap() {
    if(!mapIconTexture.loadFromFile("textures\\texture.png")){
        return;
    }
    if(!backgroundTexture.loadFromFile("textures\\blue.png")){
        return;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setTextureRect(sf::IntRect (0,0,sizeBackgroundW,sizeBackgroundH));
    backgroundSprite.setPosition(0,0);
}

MiniMap::MiniMap(int typeRoom,sf::Texture &texture, int x, int y, int sizeW, int sizeH) : sizeW(sizeW), sizeH(sizeH), typeRoom(typeRoom){

    mapIconSprite.setTexture(texture);
    mapIconSprite.setTextureRect(sf::IntRect (0,0,sizeW,sizeH));
    mapIconSprite.setPosition(x,y);

}

void MiniMap::draw(sf::RenderWindow &window, std::vector<MiniMap> &miniMapVector) {
    window.draw(backgroundSprite);
    for (int i = 0; i < miniMapVector.size(); ++i) {
        window.draw(miniMapVector[i].mapIconSprite);
    }
}

void MiniMap::start(std::vector<MiniMap> &miniMapVec) {

}

void MiniMap::update(std::vector<MiniMap> &miniVec) {

}

int MiniMap::getBackgroundWidth() {
    return sizeBackgroundW;
}

int MiniMap::getBackgroundHeight() {
    return sizeBackgroundH;
}

sf::Sprite *MiniMap::getSpite() {
    return &mapIconSprite;
}

int MiniMap::getSizeW() {
    return sizeW;
}

int MiniMap::getSizeH() {
    return sizeH;
}

int MiniMap::getTypeRoom() {
    return typeRoom;
}


