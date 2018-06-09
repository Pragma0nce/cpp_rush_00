#include "Enemy.hpp"

void Enemy::update(Game *world)
{
    GameEntity::update(world);
    //moveLeft(world);
}

Enemy::Enemy(char sprite, ENTITY_TYPE type)
:GameEntity(sprite, type)
{

}