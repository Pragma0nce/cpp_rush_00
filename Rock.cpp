#include "Rock.hpp"

void Rock::update(Game *world, int time)
{

}

Rock::Rock(char sprite, ENTITY_TYPE type)
:GameEntity(sprite, type)
{

}

Rock& Rock::operator=(const Rock& other)
{
    GameEntity::operator=(other);
    return (*this);
};

Rock::Rock(Rock &other)
:GameEntity(other)
{

}

Rock::Rock() 
{

}

Rock::~Rock()
{

}