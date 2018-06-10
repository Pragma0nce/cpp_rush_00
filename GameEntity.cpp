#include "GameEntity.hpp"
#include "Game.hpp"
#include <iostream>
#include <curses.h>


GameEntity::GameEntity()
{
    m_alive = true;
    m_colorPair = DEFAULT_PAIR;
}

GameEntity::GameEntity(char sprite, ENTITY_TYPE type)
:m_sprite(sprite), m_type(type)
{
     m_alive = true;
    m_moveSpeed = 1;

    m_colorPair = DEFAULT_PAIR;

    init_pair(DEFAULT_PAIR, COLOR_WHITE, COLOR_BLACK);
}

void GameEntity::update(Game *world, int time)
{
    if (m_x <= 0 || m_x >= BOARD_SIZE_X - 1 | m_y <= 0 || m_y >= BOARD_SIZE_Y - 1)
        die();
}

void GameEntity::processInput(Game *world, int input)
{

}


bool GameEntity::move(Game *world, int x, int y)
{
    if (world->board[x][y].isEmpty())
    { 
        world->board[m_x][m_y].setEntity(0);
        world->board[x][y].setEntity(this);
        return true;
    }
    else 
    {
        resolveCollision(world, world->board[x][y].getEntity());
        return false;
    }
}


void GameEntity::moveLeft(Game *world)
{
    if (move(world, m_x - 1, m_y))
        m_x--;
}

void GameEntity::moveRight(Game *world)
{
    if (move(world, m_x + 1, m_y))
        m_x++;
}
void GameEntity::moveUp(Game *world)
{
    if (move(world, m_x, m_y - 1))
        m_y--;
}
void GameEntity::moveDown(Game *world)
{
    if (move(world, m_x, m_y + 1))
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

int GameEntity::getColorPair()
{
    return m_colorPair;
}

GameEntity::~GameEntity()
{

}

GameEntity::GameEntity(GameEntity &other)
{
    m_sprite = other.m_sprite;
    m_colorPair = other.m_colorPair;
    m_type = other.m_type;
    m_moveSpeed = other.m_type;
    m_x = other.m_x;
    m_y = other.m_y;
    m_alive = other.m_alive;
}
GameEntity& GameEntity::operator=(const GameEntity& other)
{
    m_sprite = other.m_sprite;
    m_colorPair = other.m_colorPair;
    m_type = other.m_type;
    m_moveSpeed = other.m_type;
    m_x = other.m_x;
    m_y = other.m_y;
    m_alive = other.m_alive;
    return (*this);
}