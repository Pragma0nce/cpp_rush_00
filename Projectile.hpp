#pragma once
#include "GameEntity.hpp"

class Projectile : public GameEntity
{
private:
    int m_direction;
public:
    Projectile(char c, ENTITY_TYPE type);
    void setDirection(int dir);
    void update(Game *world, int time);
    void resolveCollision(Game *world, GameEntity *other);
};