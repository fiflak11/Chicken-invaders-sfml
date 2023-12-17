#ifndef CHICKEN_H
#define CHICKEN_H
#include "SFML/Graphics.hpp"

class Chicken{
    int hp, dmg;
    float speed;
    sf::RectangleShape chicken;
public:
    Chicken(int, int, float, int, int);
    ~Chicken();
    sf::RectangleShape getChickenRect();
    void chickenMove(char side);
};
#endif
