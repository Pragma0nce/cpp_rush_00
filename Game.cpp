#include "Game.hpp"
#include <iostream>
#include <ncurses.h>

void Game::init()
{
    m_entities = new GameEntity*[m_max_entities];
    m_running = true;
}

Game::Game()
{
    m_num_entities = 0;
    m_max_entities = 50;
}

void Game::addEntity(GameEntity *entity, int x, int y)
{
    board[x][y].setEntity(entity);
    entity->setPosition(x,y);
    
    m_entities[m_num_entities++] = entity;

}

void Game::update()
{
    for (int i = 0; i < m_num_entities; i++)
    {
        if (m_entities[i]->isAlive())
        {
            m_entities[i]->update(this);
        }
    }
}

void Game::processInput(int ch)
{
    for (int i = 0; i < m_num_entities; i++)
    {
        if (m_entities[i]->isAlive())
        {
            m_entities[i]->processInput(this, ch);
        }
    }    
}

void Game::render()
{
    for (int i = 0; i < BOARD_SIZE_Y; i++)
    {
        for (int j = 0; j < BOARD_SIZE_X; j++)
        {
            wmove(stdscr, i, j);
            addch(board[j][i].getSprite()); 
        }
        refresh();
    }
}


bool Game::isRunning()
{
    return m_running;
}

void Game::stopRunning()
{
    m_running = false;
}