#include "game.h"
#include "ship.h"
#include "SFML/Graphics.hpp"

#include <iostream>
Game::Game(int w, int h, int diff): width(w), height(h), difficulty(diff){
}
void Game::start(){
    sf::RenderWindow window(sf::VideoMode(this->width, this->height), "Chicken Invaders");
    //window.setFramerateLimit(60);
    Ship ship(0,0,0,20,4,"green",this->width,this->height);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.key.code==sf::Keyboard::D && event.type==sf::Event::KeyPressed)
                ship.speedUpShip(true);
            else if (event.key.code==sf::Keyboard::A && event.type==sf::Event::KeyPressed)
                ship.speedUpShip(false);
        }

        window.clear();

        ship.moveShip();
        window.draw(ship.getShipRect());

        window.display();
    }
}
