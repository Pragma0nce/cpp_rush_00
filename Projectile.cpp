#include "Projectile.hpp"
#include <iostream>
#include "Player.hpp"
#include <curses.h>

Projectile::Projectile(char sprite, ENTITY_TYPE type)
:GameEntity(sprite, type)
{
    init_pair(BULLET_PAIR, COLOR_YELLOW, COLOR_BLACK);
    m_colorPair = BULLET_PAIR;
}

void Projectile::setDirection(int dir)
{
    m_direction = dir;
}

void Projectile::update(Game *world, int time)
{
    GameEntity::update(world, time);
    if (isAlive())
    {
        if (m_direction < 0)
        {
            moveLeft(world);
        }
        else
        {
            moveRight(world);
        }
        // std::cout << "Projectile: " << m_x << ":" << m_y << std::endl;
    }
}

void Projectile::resolveCollision(Game *world, GameEntity *other)
{
    if (other->getType() == PLAYER)
    {
        Player* p = dynamic_cast<Player*>(other);
        p->takeDamage(world);
    }
    else if (other->getType() == ENEMY)
    {
        other->die();
    }
    this->die();
}

