//
// Created by nicki on 07.05.2024.
//

#include "Map.h"
#include "Window.h"
#include "iostream"

Map::Map() {
    if(!texture.loadFromFile("textures\\texture.png")){
        return;
    }
//    sprite.setPosition(Window::getWindowWidth()/2,Window::getWindowHeight()/2);
}
Map::Map(sf::Texture &texture, int x, int y, int sizeW, int sizeH) : sizeH(sizeH), sizeW(sizeW) {
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (0,0,sizeW,sizeH));
    sprite.setPosition(x,y);
}

void Map::start(std::vector<Map> &mapVector) {
    mapVector.reserve(5);
    int randomNum = rand()%4 + 1;

    mapVector.emplace_back(Map(texture,0,0,600,600));

    switch (randomNum) {
        case 1:
            mapVector.emplace_back(Map(texture,mapVector[0].sprite.getPosition().x+600,mapVector[0].sizeH/4,600,300));
            break;
        case 2:
            mapVector.emplace_back(Map(texture,mapVector[0].sprite.getPosition().x-600,mapVector[0].sizeH/4,600,300));
            break;
        case 3:
            mapVector.emplace_back(Map(texture,mapVector[0].sizeW/4,mapVector[0].sprite.getPosition().y+600,300,600));
            break;
        case 4:
            mapVector.emplace_back(Map(texture,mapVector[0].sizeW/4,mapVector[0].sprite.getPosition().y-600,300,600));
            break;
    }

    std::cout << mapVector[0].sprite.getPosition().x << " " << mapVector[0].sprite.getPosition().y << std::endl;
    std::cout << mapVector[1].sprite.getPosition().x << " " << mapVector[1].sprite.getPosition().y << std::endl;
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




