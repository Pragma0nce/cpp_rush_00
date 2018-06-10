#pragma once
#include <time.h> 
#include "Timer.hpp"

class Game;


class EnemySpawner 
{
private:
    Game *m_world;
    Timer m_timer;
public:
    EnemySpawner(Game *world);
    void update(int time);
    
};