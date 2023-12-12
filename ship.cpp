#include "ship.h"
#include "SFML/Graphics.hpp"
#include <iostream>

Ship::Ship(int h, int d, float s, float mS, float acc, int wid, int hei): hp(h), dmg(d), speed(s), maxSpeed(mS), acceleration(acc), screenHeight(hei), screenWidth(wid){
    ship.setSize(sf::Vector2f(80,80));
    ship.setOrigin(40,80);
    ship.setFillColor(sf::Color::Green);
    ship.setPosition(sf::Vector2f(this->screenWidth/2,this->screenHeight-40));
}
sf::RectangleShape Ship::getShipRect(){
    return this->ship;
}
void Ship::shipMove(char side){
    if(side=='r' && speed+acceleration<maxSpeed)
        speed+=acceleration;
    else if(side=='l' && speed-acceleration>-maxSpeed)
        speed-=acceleration;
    else{
        if(speed>0)
            speed-=acceleration/2;
        else if(speed<0)
            speed+=acceleration/2;
        if(speed<acceleration && speed>-acceleration)
            speed=0;
    }
    sf::Vector2f pos = this->ship.getPosition();
    if(pos.x<ship.getSize().x/2 || pos.x>screenWidth-ship.getSize().x/2)
        speed=-speed;
    ship.setPosition(pos.x + speed, pos.y);
}
