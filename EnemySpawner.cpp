#include "EnemySpawner.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include <stdlib.h>
#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

EnemySpawner::EnemySpawner(Game *world)
{
    srand (time(NULL));
    m_world = world;

    m_timer.reset();
}

void EnemySpawner::update(int time)
{
    int randY = rand() % (BOARD_SIZE_Y-2) + 1;

    // std::cout << m_timer.elapsed() << std::endl;

    if (m_timer.elapsed()>= 1)
    {
         Enemy *enemy = new Enemy('@', ENEMY);
         m_world->addEntity(enemy, BOARD_SIZE_X - 2, randY);
         m_timer.reset();
    }
}