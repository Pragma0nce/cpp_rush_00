#pragma once
#include "GameEntity.hpp"

class Rock : public GameEntity
{
private: 
public:
    Rock(char sprite, ENTITY_TYPE type);
    void update(Game *world, int time);
};