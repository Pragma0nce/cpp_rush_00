#pragma once
#include "GameEntity.hpp"


class Projectile : public GameEntity
{
private:
    ENTITY_TYPE m_owner;
    int m_direction;

protected:
    Projectile();
    Projectile(Projectile &other);
    Projectile& operator=(const Projectile& other);
public:
    Projectile(char c, ENTITY_TYPE type, ENTITY_TYPE owner);
    void setDirection(int dir);
    void update(Game *world, int time);
    void resolveCollision(Game *world, GameEntity *other);
    ~Projectile();
};