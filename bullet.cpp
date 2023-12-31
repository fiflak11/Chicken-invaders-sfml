#include "bullet.h"
#include "SFML/Graphics.hpp"
#include <iostream>

Bullet::Bullet(int d, float s, sf::Vector2f sPosition): dmg(d), speed(s){
    bullet.setSize(sf::Vector2f(10,10));
    bullet.setFillColor(sf::Color::Blue);
    bullet.setPosition(sPosition);
}
Bullet::~Bullet(){}

sf::RectangleShape Bullet::getBulletRect(){
    return bullet;
}
void Bullet::bulletMove(){
    sf::Vector2f pos = bullet.getPosition();
    bullet.setPosition(pos.x, pos.y-speed);
}
