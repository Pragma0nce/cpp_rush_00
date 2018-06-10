#include "Rock.hpp"
#include "Player.hpp"

void Rock::update(Game *world, int time)
{
    if (this->m_shouldMove )
    {
        if (time >= 5)
        {
            GameEntity::update(world, time);
            moveLeft(world);
        }
    }
}

void Rock::resolveCollision(Game *world, GameEntity *other)
{
    if (other->getType() == ENEMY){
        other->die();
    }
    else if (other->getType() == PLAYER)
    {
        Player* p = dynamic_cast<Player*>(other);
        p->takeDamage(world);      
        die(); 
    }
    else if (other->getType() == COLLIDABLE){
        die();
    }
}

Rock::Rock(char sprite, ENTITY_TYPE type)
:GameEntity(sprite, type)
{
    m_shouldMove = false;
}

Rock& Rock::operator=(const Rock& other)
{
    GameEntity::operator=(other);
    return (*this);
};

void Rock::move()
{
    m_shouldMove = true;
}

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