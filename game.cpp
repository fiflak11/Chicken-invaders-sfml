#include "game.h"
#include "ship.h"
#include "SFML/Graphics.hpp"

#include <iostream>
Game::Game(int w, int h, int diff): width(w), height(h), difficulty(diff){
}
void Game::start(){
    sf::RenderWindow window(sf::VideoMode(this->width, this->height), "Chicken Invaders");
    window.setFramerateLimit(60);
    Ship ship(0,0,0.0,20.0,0.5,this->width,this->height);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            ship.shipMove('r');
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            ship.shipMove('l');
        else
            ship.shipMove('n');

        window.clear();
        window.draw(ship.getShipRect());
        window.display();
    }
}
