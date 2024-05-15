//
// Created by nicki on 07.05.2024.
//

#include "Map.h"
#include "Window.h"
#include "iostream"
#include <fmt/core.h>
#include <fmt/ranges.h>

Map::Map() {
    if(!texture.loadFromFile("textures\\texture.png")){
        return;
    }
    if(!textureSpawn.loadFromFile("textures\\red.png")){
        return;
    }
}
Map::Map(sf::Texture &texture, int x, int y, int sizeW, int sizeH) : sizeH(sizeH), sizeW(sizeW) {
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (0,0,sizeW,sizeH));
    sprite.setPosition(x,y);
}

void Map::start(std::vector<Map> &mapVector,std::vector<MiniMap> &miniMapVec) {
    mapVector.reserve(8);
    miniMapVec.reserve(8);

    mapVector.emplace_back(Map(texture,Window::getWindowWidth()/2-450,Window::getWindowHeight()/2-450,900,900));
    miniMapVec.emplace_back(MiniMap(1,textureSpawn,miniMap.getBackgroundWidth()/10,miniMap.getBackgroundHeight()/3,30,30));
    std::cout << "0 : " << mapVector[0].sprite.getPosition().x << " " << mapVector[1].sprite.getPosition().y << std::endl;
    fmt::println("{}",miniMap.getBackgroundHeight());
    char way;

    for (int i = 0; i < 1; ++i) {
        int randomNum = rand()%3 + 1;
        switch (randomNum) {
            case 1:
                mapVector.emplace_back(Map(texture,mapVector[i].sprite.getPosition().x+mapVector[i].sizeW,mapVector[i].sprite.getPosition().y + mapVector[i].sizeH/3,900,300));
                mapVector.emplace_back(Map(texture,mapVector[i+1].sprite.getPosition().x+mapVector[i+1].sizeW,mapVector[0].sprite.getPosition().y,900,900));
                miniMapVec.emplace_back(MiniMap(2,texture,miniMapVec[i].getSpite()->getPosition().x+miniMapVec[i].getSizeW(),miniMapVec[i].getSpite()->getPosition().y + miniMapVec[i].getSizeH()/3,30,10));
                miniMapVec.emplace_back(MiniMap(1,texture,miniMapVec[i+1].getSpite()->getPosition().x+miniMapVec[i+1].getSizeW(),miniMapVec[0].getSpite()->getPosition().y,30,30));
                way = 'R';
                break;
            case 2:
                mapVector.emplace_back(Map(texture,mapVector[i].sprite.getPosition().x + mapVector[i].sizeW/3,mapVector[i].sprite.getPosition().y+mapVector[i].sizeH,300,900));
                mapVector.emplace_back(Map(texture,mapVector[0].sprite.getPosition().x,mapVector[i+1].sprite.getPosition().y+mapVector[i+1].sizeH,900,900));
                miniMapVec.emplace_back(MiniMap(2,texture,miniMapVec[i].getSpite()->getPosition().x + miniMapVec[i].getSizeW()/3,miniMapVec[i].getSpite()->getPosition().y+miniMapVec[i].getSizeH(),10,30));
                miniMapVec.emplace_back(MiniMap(1,texture,miniMapVec[0].getSpite()->getPosition().x,miniMapVec[i+1].getSpite()->getPosition().y+miniMapVec[i+1].getSizeH(),30,30));
                way = 'D';
                break;
            case 3:
                mapVector.emplace_back(Map(texture,mapVector[i].sprite.getPosition().x + mapVector[i].sizeW/3,mapVector[i].sprite.getPosition().y-mapVector[i].sizeH,300,900));
                mapVector.emplace_back(Map(texture,mapVector[0].sprite.getPosition().x,mapVector[i+1].sprite.getPosition().y-mapVector[i+1].sizeH,900,900));
                miniMapVec.emplace_back(MiniMap(2,texture,miniMapVec[i].getSpite()->getPosition().x + miniMapVec[i].getSizeW()/3,miniMapVec[i].getSpite()->getPosition().y-miniMapVec[i].getSizeH(),10,30));
                miniMapVec.emplace_back(MiniMap(1,texture,miniMapVec[0].getSpite()->getPosition().x,miniMapVec[i+1].getSpite()->getPosition().y-miniMapVec[i+1].getSizeH(),30,30));
                way = 'U';
                break;
        }
    }
    for (int i = 0; i < 1; ++i) {
        int randomNum = rand()%4 + 1;
        bool isTrueRandNum = false;
        while(!isTrueRandNum){
            if(way == 'U' && randomNum == 4 || way == 'D' && randomNum == 3 || way == 'U' && randomNum == 2){
                randomNum = rand()%4 + 1;
            }else if((way == 'D' && randomNum == 3) || (way == 'D' && randomNum == 4) || (way == 'D' && randomNum == 2)){
                randomNum = rand()%4 + 1;
            }else if(way == 'R' && randomNum == 2){
                randomNum = rand()%4 + 1;
            }else if(way == 'L' && randomNum == 1){
                randomNum = rand()%4 + 1;
            }else {
                isTrueRandNum = true;
            }
        }
        fmt::println("randNum = {}", randomNum);
        switch (randomNum) {
            case 1:
                mapVector.emplace_back(Map(texture,mapVector[i+2].sprite.getPosition().x+mapVector[i+2].sizeW,mapVector[i+2].sprite.getPosition().y + mapVector[i+2].sizeH/3,900,300));
                mapVector.emplace_back(Map(texture,mapVector[i+3].sprite.getPosition().x+mapVector[i+3].sizeW,mapVector[i+2].sprite.getPosition().y,900,900));
                miniMapVec.emplace_back(MiniMap(2,texture,miniMapVec[i+2].getSpite()->getPosition().x+miniMapVec[i+2].getSizeW(),miniMapVec[i+2].getSpite()->getPosition().y + miniMapVec[i+2].getSizeH()/3,30,10));
                miniMapVec.emplace_back(MiniMap(1,texture,miniMapVec[i+3].getSpite()->getPosition().x+miniMapVec[i+3].getSizeW(),miniMapVec[i+2].getSpite()->getPosition().y,30,30));
                way = 'R';
                break;
            case 2:
                mapVector.emplace_back(Map(texture,mapVector[i+2].sprite.getPosition().x-mapVector[i+2].sizeW,mapVector[i+2].sprite.getPosition().y + mapVector[i+2].sizeH/3,900,300));
                mapVector.emplace_back(Map(texture,mapVector[i+3].sprite.getPosition().x-mapVector[i+3].sizeW,mapVector[i+2].sprite.getPosition().y,900,900));
                miniMapVec.emplace_back(MiniMap(2,texture,miniMapVec[i+2].getSpite()->getPosition().x-miniMapVec[i+2].getSizeW(),miniMapVec[i+2].getSpite()->getPosition().y + miniMapVec[i+2].getSizeH()/3,30,10));
                miniMapVec.emplace_back(MiniMap(1,texture,miniMapVec[i+3].getSpite()->getPosition().x-miniMapVec[i+3].getSizeW(),miniMapVec[i+2].getSpite()->getPosition().y,30,30));
                way = 'L';
                break;
            case 3:
                mapVector.emplace_back(Map(texture,mapVector[i+2].sprite.getPosition().x + mapVector[i+2].sizeW/3,mapVector[i].sprite.getPosition().y+mapVector[i+2].sizeH,300,900));
                mapVector.emplace_back(Map(texture,mapVector[i+2].sprite.getPosition().x,mapVector[i+3].sprite.getPosition().y+mapVector[i+3].sizeH,900,900));
                miniMapVec.emplace_back(MiniMap(2,texture,miniMapVec[i+2].getSpite()->getPosition().x + miniMapVec[i+2].getSizeW()/3,miniMapVec[i+2].getSpite()->getPosition().y+miniMapVec[i].getSizeH(),10,30));
                miniMapVec.emplace_back(MiniMap(1,texture,miniMapVec[i+2].getSpite()->getPosition().x,miniMapVec[i+3].getSpite()->getPosition().y+miniMapVec[i+3].getSizeH(),30,30));
                way = 'D';
                break;
            case 4:
                mapVector.emplace_back(Map(texture,mapVector[i+2].sprite.getPosition().x + mapVector[i+2].sizeW/3,mapVector[i].sprite.getPosition().y-mapVector[i+2].sizeH,300,900));
                mapVector.emplace_back(Map(texture,mapVector[i+2].sprite.getPosition().x,mapVector[i+3].sprite.getPosition().y-mapVector[i+3].sizeH,900,900));
                miniMapVec.emplace_back(MiniMap(2,texture,miniMapVec[i+2].getSpite()->getPosition().x + miniMapVec[i+2].getSizeW()/3,miniMapVec[i+2].getSpite()->getPosition().y-miniMapVec[i].getSizeH(),10,30));
                miniMapVec.emplace_back(MiniMap(1,texture,miniMapVec[i+2].getSpite()->getPosition().x,miniMapVec[i+3].getSpite()->getPosition().y-miniMapVec[i+3].getSizeH(),30,30));
                way = 'U';
                break;
            default:
                break;
        }


//        switch (randomNum) {
//            case 1:
//            case 2:
//            case 3:
//            case 4:
//        }
//        switch (randomNum) {
//            case 1:
//                mapVector.emplace_back(Map(texture,mapVector[i+2].sprite.getPosition().x+mapVector[i+2].sizeW,mapVector[i+2].sizeH/3,900,300));
//                mapVector.emplace_back(Map(texture,mapVector[i+3].sprite.getPosition().x+mapVector[i+3].sizeW,mapVector[i+3].sizeH-300,900,900));
//                break;
//            case 2:
//                mapVector.emplace_back(Map(texture,mapVector[i+2].sprite.getPosition().x-mapVector[i+2].sizeW,mapVector[i+2].sizeH/3,900,300 ));
//                mapVector.emplace_back(Map(texture,mapVector[i+3].sprite.getPosition().x-mapVector[i+3].sizeW,mapVector[i+3].sizeH-300,900,900));
//                break;
//            case 3:
//                mapVector.emplace_back(Map(texture,mapVector[i+2].sizeW/3,mapVector[i+2].sprite.getPosition().y+mapVector[i+2].sizeH,300,900));
//                mapVector.emplace_back(Map(texture,mapVector[i+3].sizeW-300,mapVector[i+3].sprite.getPosition().y+mapVector[i+3].sizeH,900,900));
//                break;
//            case 4:
//                mapVector.emplace_back(Map(texture,mapVector[i+2].sizeW/3,mapVector[i+2].sprite.getPosition().y-mapVector[i+2].sizeH,300,900));
//                mapVector.emplace_back(Map(texture,mapVector[i+3].sizeW-300,mapVector[i+3].sprite.getPosition().y-mapVector[i+3].sizeH,900,900));
//                break;
//        }
    }

//    std::cout << "1 : "<< mapVector[1].sprite.getPosition().x << " " << mapVector[1].sprite.getPosition().y << std::endl;
//    std::cout << "2 : "<< mapVector[2].sprite.getPosition().x << " " << mapVector[1].sprite.getPosition().y << std::endl;
//        std::cout << "4 : "<< mapVector[4].sprite.getPosition().x << " " << mapVector[1].sprite.getPosition().y << std::endl;
//        std::cout << "3 : "<< mapVector[3].sprite.getPosition().x << " " << mapVector[1].sprite.getPosition().y << std::endl;
}

void Map::move(std::vector<Map> &mapVector,Player &player) {

    if (player.movingRight) {
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].sprite.move(-player.getSpeed(), 0);
        }
    }
    if (player.movingLeft) {
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].sprite.move(player.getSpeed(), 0);
        }
    }
    if (player.movingUp) {
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].sprite.move(0, player.getSpeed());
        }
    }
    if (player.movingDown) {
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].sprite.move(0, -player.getSpeed());
        }
    }

}

void Map::draw(sf::RenderWindow &window, std::vector<Map> &mapVector) {
    for (int i = 0; i < mapVector.size(); ++i) {
        window.draw(mapVector[i].sprite);
    }
}

void Map::pressedKey(Player &player, sf::Keyboard::Key key, bool isPressed) {
    switch (key) {
        case sf::Keyboard::Key::Right:
            player.movingRight = isPressed;
            break;
        case sf::Keyboard::Key::Left:
            player.movingLeft = isPressed;
            break;
        case sf::Keyboard::Key::Up:
            player.movingUp = isPressed;
            break;
        case sf::Keyboard::Key::Down:
            player.movingDown = isPressed;
            break;
        default:
            break;
    }
}

sf::Sprite Map::getSprite() {
    return sprite;
}






