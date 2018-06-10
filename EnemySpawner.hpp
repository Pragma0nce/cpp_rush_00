#pragma once
#include <time.h> 
#include "Timer.hpp"

class Game;


class EnemySpawner 
{
private:
    Game *m_world;
    Timer m_timer;

protected:
    EnemySpawner();
    EnemySpawner(EnemySpawner &other);
    EnemySpawner& operator=(const EnemySpawner& other);
public:
    EnemySpawner(Game *world);
    void update(int time);
    ~EnemySpawner();
    
};