//
// Created by nicki on 06.05.2024.
//

#ifndef SOULKNIGHT_WINDOW_H
#define SOULKNIGHT_WINDOW_H
#include <SFML/Graphics.hpp>

class Window {
public:
    Window();
    void update();
private:
    sf::RenderWindow window;
    sf::Event event;
};


#endif //SOULKNIGHT_WINDOW_H
