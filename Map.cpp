//
// Created by nicki on 07.05.2024.
//

#include "Map.h"
#include "Window.h"

Map::Map() {
    if(!texture.loadFromFile("textures\\texture.png")){
        return;
    }
    sprite.setPosition(Window::getWindowWidth()/2,Window::getWindowHeight()/2);
}
Map::Map(sf::Texture &texture) {
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (0,0,500,500));
}

void Map::start(std::vector<Map> &mapVector) {
    mapVector.reserve(5);

    mapVector.emplace_back(Map(texture));
}

void Map::move(std::vector<Map> &mapVector,Player &player) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].sprite.move(-player.getSpeed(),0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].sprite.move(player.getSpeed(), 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
        for (int i = 0; i < mapVector.size(); ++i) {
            mapVector[i].sprite.move(0, player.getSpeed());
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
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




