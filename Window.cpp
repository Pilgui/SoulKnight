//
// Created by nicki on 06.05.2024.
//

#include "Window.h"

unsigned const int Window::windowWidth = 1000;
unsigned const int Window::windowHeight = 1000;

Window::Window() : window(sf::VideoMode(windowWidth,windowHeight),"SoulKnight") {
    update();
}

void Window::update() {
    const int targetFPS = 60;
    const sf::Time timePerFrame = sf::seconds(1.0f / targetFPS);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen()){
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;

        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            gameLogic.keyEvent(event);
        }


        while (timeSinceLastUpdate > timePerFrame){
            timeSinceLastUpdate -= timePerFrame;
            //actions
            gameLogic.update(window);
            //actions
        }

        window.clear(sf::Color::White);
        //draw
        gameLogic.draw(window);
        //draw
        window.display();
    }
}

int Window::getWindowWidth() {
    return windowWidth;
}

int Window::getWindowHeight() {
    return windowHeight;
}


