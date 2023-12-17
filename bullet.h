#ifndef BULLET_H
#define BULLET_H
#include "SFML/Graphics.hpp"

class Bullet{
    sf::RectangleShape bullet;
public:
    int dmg;
    float speed;
    Bullet(int, float, sf::Vector2f);
    ~Bullet();
    sf::RectangleShape getBulletRect();
    void bulletMove();
};
#endif
