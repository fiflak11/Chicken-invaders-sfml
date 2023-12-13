#ifndef GAME_H
#define GAME_H
#include "bullet.h"
#include "vector"
class Game{
    const int width, height, difficulty;
public:
    Game(int w, int h, int diff);
    void start();
    void bulletUpdate(std::vector<Bullet>& b);
};
#endif
