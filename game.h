#ifndef GAME_H
#define GAME_H

class Game{
    const int width, height, difficulty;
public:
    Game(int w, int h, int diff);
    void start();
};
#endif
