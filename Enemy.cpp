#include "Enemy.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "Game.hpp"
#include <iostream>
#include <ncurses.h>

Enemy::Enemy()
{
    
};

Enemy::~Enemy()
{

}

void Enemy::update(Game *world, int time)
{
    if (time >= 10){
        GameEntity::update(world, time);
        // std::cout << m_x << ":" << m_y << std::endl;
        moveLeft(world);
    }


    if (m_shootTimer.elapsed() >= m_randTime)
    {
        bool canShoot = false;
        // only shoot if it's clear
        for (int i = 0; i < m_x; i++)
        {
            if (world->board[i][m_y].getEntity() != 0 && world->board[i][m_y].getEntity()->getType() != ENEMY){
                canShoot = true;
            }
        }

        if (canShoot)
        {
            shootLeft(world);
            m_shootTimer.reset();
        }
    }


}

Enemy::Enemy(char sprite, ENTITY_TYPE type)
:GameEntity(sprite, type)
{
    srand (time(NULL));
    m_shootTimer.reset();
    m_randTime = rand() % 5 + 2;
    init_pair(ENEMY_PAIR, COLOR_RED, COLOR_BLACK);
    m_colorPair = ENEMY_PAIR;
}

void Enemy::resolveCollision(Game *world, GameEntity *other)
{
    if (other->getType() == PLAYER)
    {
        Player* p = dynamic_cast<Player*>(other);
        p->takeDamage(world);
    }
    die();
}

void Enemy::shootLeft(Game *world)
{
    Projectile *bullet = new Projectile('=', PROJECTILE, ENEMY);
    bullet->setDirection(-1);

    world->addEntity(bullet, m_x - 1, m_y);   
    m_randTime = rand() % 5 + 2;
}

Enemy::Enemy(Enemy &other)
{
    m_shootTimer = other.m_shootTimer;
    m_randTime = other.m_randTime;
}

Enemy& Enemy::operator=(const Enemy& other)
{
    m_shootTimer = other.m_shootTimer;
    m_randTime = other.m_randTime;
    return (*this);
}

