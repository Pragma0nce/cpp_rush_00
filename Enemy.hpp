#pragma once
#include "GameEntity.hpp"

class Enemy : public GameEntity
{
private:
public:
    Enemy(char sprite, ENTITY_TYPE type);
    void update(Game *world);
};