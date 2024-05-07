//
// Created by nicki on 06.05.2024.
//

#ifndef SOULKNIGHT_WINDOW_H
#define SOULKNIGHT_WINDOW_H
#include <SFML/Graphics.hpp>
#include "GameLogic.h"


class Window {
public:
    Window();
    void update();
    static int getWindowWidth();
    static int getWindowHeight();
private:
    sf::RenderWindow window;
    sf::Event event;
    GameLogic gameLogic;

    unsigned static const int windowWidth;
    unsigned static const int windowHeight;
};


#endif //SOULKNIGHT_WINDOW_H
