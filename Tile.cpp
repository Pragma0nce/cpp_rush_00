#include "Tile.hpp"
#include "GameEntity.hpp"
#include <iostream>

Tile::Tile()
{
    m_sprite = '.';
    m_entity = 0;
}

char Tile::getSprite()
{
    
    if (isEmpty())
        return ' ';
    else
    {
        if (m_entity->isAlive())
            return m_entity->getSprite();
        else
            return ' ';
    }
}
GameEntity *Tile::getEntity()
{
    return m_entity;
}

void Tile::setEntity(GameEntity *entity)
{
    m_entity = entity;
}

bool Tile::isEmpty()
{
    if (m_entity == 0)
        return true;
    else
    {
        return false;
    }
}