#include "game.h"
#include "ship.h"
#include "bullet.h"
#include "SFML/Graphics.hpp"
#include <vector>

#include <iostream>
Game::Game(int w, int h, int diff): width(w), height(h), difficulty(diff){}

void Game::start(){
    sf::RenderWindow window(sf::VideoMode(this->width, this->height), "Chicken Invaders");
    window.setFramerateLimit(60);
    std::vector<Bullet> bullets;
    Ship ship(0,0,0.0,20.0,0.5,this->width,this->height);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                bullets.push_back(Bullet(5,5,ship.getShipRect().getPosition()));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            ship.shipMove('r');
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            ship.shipMove('l');
        else
            ship.shipMove('n');
        bulletUpdate(bullets);

        window.clear();
        window.draw(ship.getShipRect());
        for(auto& bullet : bullets)
            window.draw(bullet.getBulletRect());
        window.display();
    }
}

void Game::bulletUpdate(std::vector<Bullet>& bullets){
    for(auto& bullet : bullets){
        sf::Vector2f pos = bullet.getBulletRect().getPosition();
        bullet.getBulletRect().setPosition(pos.x, pos.y-bullet.speed);
    }

}
