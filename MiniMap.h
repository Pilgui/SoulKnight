//
// Created by nicki on 13.05.2024.
//

#ifndef SOULKNIGHT_MINIMAP_H
#define SOULKNIGHT_MINIMAP_H
#include <SFML/Graphics.hpp>

class MiniMap {
public:
    MiniMap();
    MiniMap(int typeRoom, sf::Texture &texture, int x, int y, int sizeW, int sizeH);
    void draw(sf::RenderWindow &window, std::vector<MiniMap> &miniMapVector);
    void start(std::vector<MiniMap> &miniMapVec);
    void update(std::vector<MiniMap> &miniVec);
    int getBackgroundWidth();
    int getBackgroundHeight();
    sf::Sprite *getSpite();
    int getSizeW();
    int getSizeH();
    int getTypeRoom();
private:
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Sprite mapIconSprite;
    sf::Texture mapIconTexture;

    int sizeW;
    int sizeH;

    const int sizeBackgroundW = 400;
    const int sizeBackgroundH = 250;

    int typeRoom;
};


#endif //SOULKNIGHT_MINIMAP_H
