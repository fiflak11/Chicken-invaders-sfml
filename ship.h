#ifndef SHIP_H
#define SHIP_H
#include "SFML/Graphics.hpp"
#include <string>

class Ship{
    int hp, dmg, speed, maxSpeed, acceleration, screenWidth, screenHeight;
    std::string color;
    sf::RectangleShape ship;
public:
    Ship(int h, int d, int s, int mS, int acc, std::string c, int wid, int hei);
    sf::RectangleShape getShipRect();
    void moveShip();
    void speedUpShip(bool direct);// false-left, true-right
};
#endif
