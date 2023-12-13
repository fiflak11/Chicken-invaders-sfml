#ifndef BULLET_H
#define BULLET_H
#include "SFML/Graphics.hpp"

class Bullet{
    sf::RectangleShape bullet;
public:
    const int dmg;
    const float speed;
    Bullet(int, float, sf::Vector2f);
    sf::RectangleShape& getBulletRect();
};
#endif
