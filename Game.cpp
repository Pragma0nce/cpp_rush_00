#include "Game.hpp"
#include <iostream>
#include <ncurses.h>
#include "Rock.hpp"

void Game::init()
{
    m_entities = new GameEntity*[m_max_entities];
    m_running = true;
    createBorders();

    m_lives = 3;
    m_score = 0;
    m_gameSpeed = 10000;
    m_spawner = new EnemySpawner(this);
    m_rockspawner = new AsteroidSpawner(this);
    m_timer.reset();

    m_gameTime.reset();
}

void Game::createBorders()
{
    for (int i = 0; i < BOARD_SIZE_X; i++)
    {
        Rock *rock = new Rock('#', COLLIDABLE);
        addEntity(rock, i, 0);

        Rock *rock2 = new Rock('#', COLLIDABLE);
        addEntity(rock2, i, BOARD_SIZE_Y - 1);
    }

    for (int i = 1; i < BOARD_SIZE_Y - 1; i++)
    {
        Rock *rock = new Rock('|', COLLIDABLE);
        addEntity(rock, 0, i);
    }
}

void Game::addToScore(int n){
    m_score+=n;
}

Game::Game()
{
    m_num_entities = 0;
    m_max_entities = 500;
}

void Game::addEntity(GameEntity *entity, int x, int y)
{
    board[x][y].setEntity(entity);
    entity->setPosition(x,y);
    
    m_entities[m_num_entities++] = entity;

}

void Game::update(int time)
{
    for (int i = 0; i < m_num_entities; i++)
    {
        if (m_entities[i]->isAlive())
        {
            m_entities[i]->update(this, time);
        }
    }

    m_spawner->update(time);
    m_rockspawner->update(time);
    removeDeadEntities();

    if (m_timer.elapsed() >= 5)
    {
        m_gameSpeed -= 100;
        m_timer.reset();
    }
}

void Game::processInput(int ch)
{

    if (ch == 27)
    {
        this->stopRunning();
    }

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

            if (board[j][i].getEntity() != 0)
            {
                wattron(stdscr, COLOR_PAIR(board[j][i].getEntity()->getColorPair()));
            }
            else 
            {
                wattron(stdscr, COLOR_PAIR(1));
            }
            addch(board[j][i].getSprite()); 
        }
        refresh();
    }
    wmove(stdscr, BOARD_SIZE_Y, BOARD_SIZE_Y);
    wprintw(stdscr, "LIVES: ");
    wprintw(stdscr, "%d", m_lives);
    wprintw(stdscr, "            SCORE: ");
    wprintw(stdscr, "%d", m_score);
    wprintw(stdscr, "            TIME: ");
    wprintw(stdscr, "%d", getGameTime());
}

void Game::removeDeadEntities()
{
    bool atEnd = false;;
    int i = 0;
    
    while (!atEnd)
    {
        if (m_entities[i]->isAlive() == false)
        {
            GameEntity *temp = m_entities[i];
            m_entities[i] = m_entities[m_num_entities - 1];
            m_entities[m_num_entities - 1] = temp;

            board[temp->getPosX()][temp->getPosY()].setEntity(0);
            // std::cout << "Deleting entity at: " << temp->getPosX() <<":"<< temp->getPosY() << std::endl;

            delete m_entities[m_num_entities - 1];
            m_num_entities--;
            i--;
        }
        i++;
        if (i >= m_num_entities)
            atEnd = true;
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

int Game::getLives()
{
    return m_lives;
}
void Game::setLives(int n)
{
    m_lives = n;
    if (m_lives == 0)
    {
        stopRunning();
    }
}

int Game::getScore()
{
    return m_score;
}

Game::Game(Game &other)
{
    m_lives = other.m_lives;
    m_score = other.m_score;

    m_entities = other.m_entities;
    m_num_entities = other.m_num_entities;
    m_max_entities = other.m_max_entities;
    m_running = other.m_running;;

    m_spawner = other.m_spawner;
}

Game& Game::operator=(const Game& other)
{
    m_lives = other.m_lives;
    m_score = other.m_score;

    m_entities = other.m_entities;
    m_num_entities = other.m_num_entities;
    m_max_entities = other.m_max_entities;
    m_running = other.m_running;;

    m_spawner = other.m_spawner;
    return (*this);
}

int Game::getGameSpeed()
{
    return m_gameSpeed;
}

int Game::getGameTime()
{
    return m_gameTime.elapsed();
}

Game::~Game()
{

}