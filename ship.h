#ifndef SHIP_H
#define SHIP_H
#include "SFML/Graphics.hpp"

class Ship{
    int hp, dmg;
    float speed, maxSpeed, acceleration;
    const int screenWidth, screenHeight;
    sf::RectangleShape ship;
public:
    Ship(int, int, float, float, float, int, int);
    sf::RectangleShape getShipRect();
    void shipMove(char side);// r-right l-left n-just slow down ship
};
#endif
