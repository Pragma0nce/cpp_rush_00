#include "AsteroidSpawner.hpp"
#include "Rock.hpp"
#include "Game.hpp"
#include <stdlib.h>
#include <iostream>
#include <chrono>

AsteroidSpawner::AsteroidSpawner (Game *world)
{
    srand (time(NULL));
    m_world = world;

    m_timer.reset();
}


void AsteroidSpawner::update(int time)
{
    int randY = rand() % (BOARD_SIZE_Y-2) + 1;

    // std::cout << m_timer.elapsed() << std::endl;

    if (m_timer.elapsed()>= 3)
    {
         Rock *rock = new Rock('#', COLLIDABLE);
         rock->move();
         m_world->addEntity(rock, BOARD_SIZE_X - 2, randY);
         m_timer.reset();
    }
}


AsteroidSpawner::AsteroidSpawner()
{

}
AsteroidSpawner::AsteroidSpawner(AsteroidSpawner &other)
{
    m_world = other.m_world;
    m_timer = other.m_timer;
}

AsteroidSpawner& AsteroidSpawner::operator=(const AsteroidSpawner& other)
{
    m_world = other.m_world;
    m_timer = other.m_timer;

    return (*this);
}

AsteroidSpawner::~AsteroidSpawner()
{

}