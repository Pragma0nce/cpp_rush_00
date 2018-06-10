#pragma once
#include "GameEntity.hpp"

class Rock : public GameEntity
{
private: 
protected:
    Rock();
    Rock(Rock &other);
    Rock& operator=(const Rock& other);
public:
    Rock(char sprite, ENTITY_TYPE type);
    void update(Game *world, int time);
    ~Rock();
};