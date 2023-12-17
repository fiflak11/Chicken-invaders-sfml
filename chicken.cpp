#include "chicken.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include<cstdlib>

Chicken::Chicken(int h, int d, float s, int x, int y): speed(s), dmg(d), hp(h){
    srand((unsigned) time(NULL));
    chicken.setSize(sf::Vector2f(40, 40));
    chicken.setFillColor(sf::Color::Red);
    chicken.setPosition(sf::Vector2f(x,y));
}
Chicken::~Chicken(){}
sf::RectangleShape Chicken::getChickenRect(){
    return this->chicken;
}
void Chicken::chickenMove(char side){
    sf::Vector2f pos=chicken.getPosition();
    if(side=='r')
        chicken.setPosition(sf::Vector2f(pos.x+speed,pos.y));
    else if(side=='l')
        chicken.setPosition(sf::Vector2f(pos.x-speed,pos.y));
    else if(side=='w'){
        if(rand()%2)
            chicken.setPosition(sf::Vector2f(pos.x-speed,pos.y));
        else
            chicken.setPosition(sf::Vector2f(pos.x+speed,pos.y));
    }

}
