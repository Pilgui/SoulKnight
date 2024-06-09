//
// Created by nicki on 07.05.2024.
//

#include "Map.h"
#include "Window.h"
#include "iostream"
#include <fmt/core.h>
#include <fmt/ranges.h>

Map::Map() {
    if(!mapTexture.loadFromFile("textures\\map.png")){
        return;
        std::cout << "error";
    }
    if(!tunnelTexture1.loadFromFile("textures\\tunnel1.png")){
        return;
    }
    if(!tunnelTexture2.loadFromFile("textures\\tunnel2.png")){
        return;
    }
    if(!miniTunnelTexture1.loadFromFile("textures\\minitunnel1.png")){
        return;
    }
    if(!miniTunnelTexture2.loadFromFile("textures\\minitunnel2.png")){
        return;
    }
    if (!miniMapTexture.loadFromFile("textures\\minimap1.png")){
        return;
    }
    if(!backgroundTexture.loadFromFile("textures\\background.png")){
        return;
    }
}
Map::Map(sf::Texture &texture, int x, int y, int sizeW, int sizeH) : sizeH(sizeH), sizeW(sizeW) {
    sprite.setTexture(texture);
//    sprite.setTextureRect(sf::IntRect (0,0,sizeW,sizeH));
    sprite.setPosition(x,y);
}

void Map::start(std::vector<Map> &mapVector,std::vector<MiniMap> &miniMapVec) {

    for (int i = -2; i < 18; ++i) {
        for (int j = -10; j < 10; j++) {
            backgroundSprite.setTexture(backgroundTexture);
            backgroundSprite.setPosition(i * 300, j * 300);
            backgroundVec.emplace_back(backgroundSprite);
        }
    }


    mapVector.reserve(8);
    miniMapVec.reserve(8);

    mapVector.emplace_back(Map(mapTexture, Window::getWindowWidth() / 2 - 450, Window::getWindowHeight() / 2 - 450, 900, 900));
    miniMapVec.emplace_back(MiniMap(1,miniMapTexture,miniMap.getBackgroundWidth()/10,miniMap.getBackgroundHeight()/2-15,30,30));

    mapVector[0].typeRoom = Map::typeRoom::SPAWN;
    std::cout << "0 : " << mapVector[0].sprite.getPosition().x << " " << mapVector[1].sprite.getPosition().y << std::endl;
    fmt::println("{}",miniMap.getBackgroundHeight());
    char way;

    for (int i = 0; i < 1; ++i) {
        int randomNum = rand()%3 + 1;
        randomNum = 1;
        switch (randomNum) {
            case 1:
                mapVector.emplace_back(Map(tunnelTexture1, mapVector[i].sprite.getPosition().x + mapVector[i].sizeW, mapVector[i].sprite.getPosition().y + mapVector[i].sizeH / 3, 900, 300));
                mapVector.emplace_back(Map(mapTexture, mapVector[i + 1].sprite.getPosition().x + mapVector[i + 1].sizeW, mapVector[0].sprite.getPosition().y, 900, 900));
                miniMapVec.emplace_back(MiniMap(2, miniTunnelTexture1, miniMapVec[i].getSpite()->getPosition().x + miniMapVec[i].getSizeW(), miniMapVec[i].getSpite()->getPosition().y + miniMapVec[i].getSizeH() / 3, 30, 10));
                miniMapVec.emplace_back(MiniMap(1, miniMapTexture, miniMapVec[i + 1].getSpite()->getPosition().x + miniMapVec[i + 1].getSizeW(), miniMapVec[0].getSpite()->getPosition().y, 30, 30));
                way = 'R';
                break;
            case 2:
                mapVector.emplace_back(Map(tunnelTexture2, mapVector[i].sprite.getPosition().x + mapVector[i].sizeW / 3, mapVector[i].sprite.getPosition().y + mapVector[i].sizeH, 300, 900));
                mapVector.emplace_back(Map(mapTexture, mapVector[0].sprite.getPosition().x, mapVector[i + 1].sprite.getPosition().y + mapVector[i + 1].sizeH, 900, 900));
                miniMapVec.emplace_back(MiniMap(2, miniTunnelTexture2, miniMapVec[i].getSpite()->getPosition().x + miniMapVec[i].getSizeW() / 3, miniMapVec[i].getSpite()->getPosition().y + miniMapVec[i].getSizeH(), 10, 30));
                miniMapVec.emplace_back(MiniMap(1, miniMapTexture, miniMapVec[0].getSpite()->getPosition().x, miniMapVec[i + 1].getSpite()->getPosition().y + miniMapVec[i + 1].getSizeH(), 30, 30));
                way = 'D';
                break;
            case 3:
                mapVector.emplace_back(Map(tunnelTexture2, mapVector[i].sprite.getPosition().x + mapVector[i].sizeW / 3, mapVector[i].sprite.getPosition().y - mapVector[i].sizeH, 300, 900));
                mapVector.emplace_back(Map(mapTexture, mapVector[0].sprite.getPosition().x, mapVector[i + 1].sprite.getPosition().y - mapVector[i + 1].sizeH, 900, 900));
                miniMapVec.emplace_back(MiniMap(2, miniTunnelTexture2, miniMapVec[i].getSpite()->getPosition().x + miniMapVec[i].getSizeW() / 3, miniMapVec[i].getSpite()->getPosition().y - miniMapVec[i].getSizeH(), 10, 30));
                miniMapVec.emplace_back(MiniMap(1, miniMapTexture, miniMapVec[0].getSpite()->getPosition().x, miniMapVec[i + 1].getSpite()->getPosition().y - miniMapVec[i + 1].getSizeH(), 30, 30));
                way = 'U';
                break;
        }
    }
    for (int i = 0; i < 1; ++i) {
        int randomNum = rand()%4 + 1;
        bool isTrueRandNum = false;
        while(!isTrueRandNum){
            if((way == 'U' && randomNum == 4) || way == 'D' && randomNum == 3 || way == 'U' && randomNum == 2){
                randomNum = rand()%4 + 1;
            }else if((way == 'D' && randomNum == 3) || (way == 'D' && randomNum == 4) || (way == 'D' && randomNum == 2)){
                randomNum = rand()%4 + 1;
            }else if(way == 'R' && randomNum == 2){
                randomNum = rand()%4 + 1;
            }else if(way == 'L' && randomNum == 1){
                randomNum = rand()%4 + 1;
            }else if (way == 'U' && randomNum == 3){
                randomNum = rand()%4 + 1;
            }else {
                isTrueRandNum = true;
            }
        }
        fmt::println("randNum = {}", randomNum);
        switch (randomNum) {
            case 1:
                mapVector.emplace_back(Map(tunnelTexture1, mapVector[i + 2].sprite.getPosition().x + mapVector[i + 2].sizeW, mapVector[i + 2].sprite.getPosition().y + mapVector[i + 2].sizeH / 3, 900, 300));
                mapVector.emplace_back(Map(mapTexture, mapVector[i + 3].sprite.getPosition().x + mapVector[i + 3].sizeW, mapVector[i + 2].sprite.getPosition().y, 900, 900));
                miniMapVec.emplace_back(MiniMap(2, miniTunnelTexture1, miniMapVec[i + 2].getSpite()->getPosition().x + miniMapVec[i + 2].getSizeW(), miniMapVec[i + 2].getSpite()->getPosition().y + miniMapVec[i + 2].getSizeH() / 3, 30, 10));
                miniMapVec.emplace_back(MiniMap(1, miniMapTexture, miniMapVec[i + 3].getSpite()->getPosition().x + miniMapVec[i + 3].getSizeW(), miniMapVec[i + 2].getSpite()->getPosition().y, 30, 30));
                way = 'R';
                break;
            case 2:
                mapVector.emplace_back(Map(tunnelTexture1, mapVector[i + 2].sprite.getPosition().x - mapVector[i + 2].sizeW, mapVector[i + 2].sprite.getPosition().y + mapVector[i + 2].sizeH / 3, 900, 300));
                mapVector.emplace_back(Map(mapTexture, mapVector[i + 3].sprite.getPosition().x - mapVector[i + 3].sizeW, mapVector[i + 2].sprite.getPosition().y, 900, 900));
                miniMapVec.emplace_back(MiniMap(2, miniTunnelTexture1, miniMapVec[i + 2].getSpite()->getPosition().x - miniMapVec[i + 2].getSizeW(), miniMapVec[i + 2].getSpite()->getPosition().y + miniMapVec[i + 2].getSizeH() / 3, 30, 10));
                miniMapVec.emplace_back(MiniMap(1, miniMapTexture, miniMapVec[i + 3].getSpite()->getPosition().x - miniMapVec[i + 3].getSizeW(), miniMapVec[i + 2].getSpite()->getPosition().y, 30, 30));
                way = 'L';
                break;
            case 3:
                mapVector.emplace_back(Map(tunnelTexture2, mapVector[i + 2].sprite.getPosition().x + mapVector[i + 2].sizeW / 3, mapVector[i].sprite.getPosition().y + mapVector[i + 2].sizeH, 300, 900));
                mapVector.emplace_back(Map(mapTexture, mapVector[i + 2].sprite.getPosition().x, mapVector[i + 3].sprite.getPosition().y + mapVector[i + 3].sizeH, 900, 900));
                miniMapVec.emplace_back(MiniMap(2, miniTunnelTexture2, miniMapVec[i + 2].getSpite()->getPosition().x + miniMapVec[i + 2].getSizeW() / 3, miniMapVec[i + 2].getSpite()->getPosition().y + miniMapVec[i].getSizeH(), 10, 30));
                miniMapVec.emplace_back(MiniMap(1, miniMapTexture, miniMapVec[i + 2].getSpite()->getPosition().x, miniMapVec[i + 3].getSpite()->getPosition().y + miniMapVec[i + 3].getSizeH(), 30, 30));
                way = 'D';
                break;
            case 4:
                mapVector.emplace_back(Map(tunnelTexture2, mapVector[i + 2].sprite.getPosition().x + mapVector[i + 2].sizeW / 3, mapVector[i].sprite.getPosition().y - mapVector[i + 2].sizeH, 300, 900));
                mapVector.emplace_back(Map(mapTexture, mapVector[i + 2].sprite.getPosition().x, mapVector[i + 3].sprite.getPosition().y - mapVector[i + 3].sizeH, 900, 900));
                miniMapVec.emplace_back(MiniMap(2, miniTunnelTexture2, miniMapVec[i + 2].getSpite()->getPosition().x + miniMapVec[i + 2].getSizeW() / 3, miniMapVec[i + 2].getSpite()->getPosition().y - miniMapVec[i].getSizeH(), 10, 30));
                miniMapVec.emplace_back(MiniMap(1, miniMapTexture, miniMapVec[i + 2].getSpite()->getPosition().x, miniMapVec[i + 3].getSpite()->getPosition().y - miniMapVec[i + 3].getSizeH(), 30, 30));
                way = 'U';
                break;
            default:
                break;
        }
    }



    for (int i = 1; i < mapVector.size(); ++i) {
        if(i == 2){
            mapVector[i].typeRoom = Map::typeRoom::ENEMY;
        }
        if(i == 4){
            mapVector[i].typeRoom = Map::typeRoom::SHOP;
        }
        if(i == 1 || i % 2 != 0){
            mapVector[i].typeRoom = Map::typeRoom::TUNNEL;
        }

    }

}



void Map::draw(sf::RenderWindow &window, std::vector<Map> &mapVector) {
    for (int i = 0; i < backgroundVec.size(); ++i) {
        window.draw(backgroundVec[i]);
    }
    for (int i = 0; i < mapVector.size(); ++i) {
        window.draw(mapVector[i].sprite);
    }

}

sf::Sprite *Map::getSprite() {
    return &sprite;
}

void Map::backGroundMoves(Player &player) {
    if (player.movingRight && player.isRightBorder) {
        for (int i = 0; i < backgroundVec.size(); ++i) {
            backgroundVec[i].move(-player.getSpeed(), 0);
        }
    }
    if (player.movingLeft && player.isLeftBorder) {
        for (int i = 0; i < backgroundVec.size(); ++i) {
            backgroundVec[i].move(player.getSpeed(), 0);
        }
    }
    if (player.movingUp && player.isTopBorder) {
        for (int i = 0; i < backgroundVec.size(); ++i) {
            backgroundVec[i].move(0,player.getSpeed());
        }
    }
    if (player.movingDown && player.isBottomBorder) {
        for (int i = 0; i < backgroundVec.size(); ++i) {
            backgroundVec[i].move(0,-player.getSpeed());
        }
    }
}










