#include "ship.h"
#include "SFML/Graphics.hpp"

Ship::Ship(int h, int d, int s, int mS, int acc, std::string c, int wid, int hei): hp(h), dmg(d), speed(s), maxSpeed(mS), acceleration(acc), color(c), screenHeight(hei), screenWidth(wid){
    ship.setSize(sf::Vector2f(80,80));
    ship.setOrigin(40,80);
    ship.setFillColor(sf::Color::Green);
    ship.setPosition(sf::Vector2f(this->screenWidth/2,this->screenHeight-40));
}
sf::RectangleShape Ship::getShipRect(){
    return this->ship;
}
void Ship::moveShip(){
    sf::Vector2f pos = this->ship.getPosition();
    ship.setPosition(pos.x + speed, pos.y);
    if(abs(speed)<acceleration)
        speed=0;
    else if(speed>0)
        speed-=acceleration/2;
    else if(speed<0)
        speed+=acceleration/2;
}
void Ship::speedUpShip(bool direction){
    if(direction)
        speed+=acceleration;
    else
        speed-=acceleration;
    if(abs(speed)>maxSpeed) //if ship move faster than maxSpeed, set speed at maximum(right) or minimum(left)
        if(speed>0)
            speed=maxSpeed;
        else
            speed=-maxSpeed;
}
