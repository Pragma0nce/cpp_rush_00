#pragma once
#include <time.h> 
#include "Timer.hpp"

class Game;


class AsteroidSpawner 
{
private:
    Game *m_world;
    Timer m_timer;

protected:
    AsteroidSpawner ();
    AsteroidSpawner (AsteroidSpawner  &other);
    AsteroidSpawner & operator=(const AsteroidSpawner & other);
public:
    AsteroidSpawner (Game *world);
    void update(int time);
    ~AsteroidSpawner ();
    
};