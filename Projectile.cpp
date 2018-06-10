#include "Projectile.hpp"
#include <iostream>
#include "Player.hpp"
#include "Game.hpp"
#include <curses.h>

Projectile::Projectile(char sprite, ENTITY_TYPE type, ENTITY_TYPE owner)
:GameEntity(sprite, type)
{
    if (owner == PLAYER)
    {
        init_pair(BULLET_PAIR, COLOR_YELLOW, COLOR_BLACK);
        m_colorPair = BULLET_PAIR;
    }
    else {
        init_pair(ENEMY_BULLET_PAIR, COLOR_CYAN, COLOR_BLACK);
        m_colorPair = ENEMY_BULLET_PAIR;        
    }
    m_owner = owner;
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
        if (m_owner == PLAYER)
            world->addToScore(10);
        other->die();
    }
    else if (other->getType() == PROJECTILE)
    {
        other->die();
    }
    this->die();
}

Projectile::Projectile()
{

}

Projectile::Projectile(Projectile &other)
:GameEntity(other)
{

}

Projectile& Projectile::operator=(const Projectile & other)
{
    GameEntity::operator=(other);
    m_owner = other.m_owner;
    m_direction = other.m_direction;
    return (*this);
}

Projectile::~Projectile()
{
    
}

