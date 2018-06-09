#include "GameEntity.hpp"
#include "Game.hpp"
#include <iostream>

GameEntity::GameEntity()
{
    m_alive = true;
}

GameEntity::GameEntity(char sprite, ENTITY_TYPE type)
:m_sprite(sprite), m_type(type)
{
     m_alive = true;
    m_moveSpeed = 1;
}

void GameEntity::update(Game *world)
{
    if (m_x < 0 || m_x >= BOARD_SIZE_X || m_y < 0 || m_y >= BOARD_SIZE_Y)
        die();
}

void GameEntity::processInput(Game *world, int input)
{

}


void GameEntity::move(Game *world, int x, int y)
{
    if (world->board[x][y].isEmpty())
    {
        world->board[m_x][m_y].setEntity(0);
        world->board[x][y].setEntity(this);
    }
}


void GameEntity::moveLeft(Game *world)
{
    move(world, m_x - 1, m_y);
    m_x--;
}

void GameEntity::moveRight(Game *world)
{
    move(world, m_x + 1, m_y);
    m_x++;
}
void GameEntity::moveUp(Game *world)
{
    move(world, m_x, m_y - 1);
    m_y--;
}
void GameEntity::moveDown(Game *world)
{
    move(world, m_x, m_y + 1);
    m_y++;
}

void GameEntity::resolveCollision(Game *world, GameEntity *other)
{

}

bool GameEntity::checkCollision(Game *world, int x, int y)
{
    if (world->board[x][y].isEmpty())
    {
        return true;
    }
    else 
    {
        resolveCollision(world, world->board[x][y].getEntity());
        return false;
    }
}


int GameEntity::getPosX()
{
    return m_x;
}

int GameEntity::getPosY()
{
    return m_y;
}

char GameEntity::getSprite()
{
    return m_sprite;
}

ENTITY_TYPE GameEntity::getType()
{
    return m_type;
}

void GameEntity::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
}

bool GameEntity::isAlive()
{
    return m_alive;
}

void GameEntity::die()
{
    m_alive = false;
}