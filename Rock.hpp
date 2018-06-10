#pragma once
#include "GameEntity.hpp"

class Rock : public GameEntity
{
private: 
    bool m_shouldMove;
protected:
    Rock();
    Rock(Rock &other);
    Rock& operator=(const Rock& other);
public:
    Rock(char sprite, ENTITY_TYPE type);
    void update(Game *world, int time);
    void resolveCollision(Game *world, GameEntity *other);

    void move();
    ~Rock();
};