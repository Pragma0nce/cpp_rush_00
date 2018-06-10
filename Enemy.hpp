#pragma once
#include "GameEntity.hpp"
#include "Timer.hpp"

class Enemy : public GameEntity
{
private:
    Timer m_shootTimer;
    int m_randTime;

protected:
    Enemy();
    Enemy(Enemy &other);
    Enemy& operator=(const Enemy& other);
public:
    Enemy(char sprite, ENTITY_TYPE type);
    void update(Game *world, int time);
    void resolveCollision(Game *world, GameEntity *other);

    void shootLeft(Game *world);
    ~Enemy();
};