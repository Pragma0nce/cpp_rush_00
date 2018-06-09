#include "Projectile.hpp"

Projectile::Projectile(char sprite, ENTITY_TYPE type)
:GameEntity(sprite, type)
{

}

void Projectile::setDirection(int dir)
{
    m_direction = dir;
}

void Projectile::update(Game *world)
{
    GameEntity::update(world);
    if (m_direction < 0)
        moveLeft(world);
    else
        moveRight(world);
}