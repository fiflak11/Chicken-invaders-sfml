#include "game.h"
#include "ship.h"
#include "bullet.h"
#include "chicken.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <memory>

#include <iostream>
Game::Game(int w, int h, int diff): width(w), height(h), difficulty(diff){}

void Game::start(){
    sf::RenderWindow window(sf::VideoMode(this->width, this->height), "Chicken Invaders");
    window.setFramerateLimit(60);
    std::vector<Bullet> bullets;
    std::vector<Chicken> chickens;
    Ship ship(0,0,0.0,20.0,0.5,this->width,this->height);

    //create chicken
    int distX=105, distY=80;
    int row=11, column=5;
    for(int i{1}; i<=row; i++)
        for(int j{1}; j<=column; j++){
            Chicken x(5,5,5,i*distX,j*distY);
            chickens.push_back(x);
        }



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                Bullet x(5,5,ship.getShipRect().getPosition());
                bullets.push_back(x);
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            ship.shipMove('r');
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            ship.shipMove('l');
        else
            ship.shipMove('n');
        bulletUpdate(bullets);

        window.clear();
        // test
        bool flag=false;
        for(auto chickenBegin = chickens.begin(); chickenBegin!=chickens.end() && chickens.size()>0; chickenBegin++){
            for(auto bulletBegin = bullets.begin(); bulletBegin!=bullets.end() && bullets.size()>0 && chickens.size()>0; bulletBegin++){
                if((*bulletBegin).getBulletRect().getGlobalBounds().intersects((*chickenBegin).getChickenRect().getGlobalBounds())){
                    bullets.erase(bulletBegin);
                    chickens.erase(chickenBegin);
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        // test
        for(auto& bullet : bullets)
            window.draw(bullet.getBulletRect());
        for(auto& chicken : chickens){
            chicken.chickenMove('w');
            window.draw(chicken.getChickenRect());
        }

        window.draw(ship.getShipRect());
        window.display();
    }
}

void Game::bulletUpdate(std::vector<Bullet>& bullets){
    for(auto& bullet : bullets){
        bullet.bulletMove();
    }

}
