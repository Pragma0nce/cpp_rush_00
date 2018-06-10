#pragma once
#include "Tile.hpp"
#include "GameEntity.hpp"
#include "EnemySpawner.hpp"
#include "AsteroidSpawner.hpp"
#include "Timer.hpp"

const int BOARD_SIZE_X = 100;
const int BOARD_SIZE_Y = 20;

class Game
{
private:
    Timer m_gameTime;
    Timer m_timer;
    int m_lives;
    int m_score;
    int m_gameSpeed;

    GameEntity **m_entities;
    int m_num_entities;
    int m_max_entities;
    bool m_running;

    EnemySpawner *m_spawner;
    AsteroidSpawner *m_rockspawner;

    void createBorders();

protected:
    Game(Game &other);
    Game& operator=(const Game& other);
public:
    Game();

    void init();
    void update(int time);
    void render();
    void processInput(int ch);

    bool isRunning();
    void stopRunning();

    Tile board[BOARD_SIZE_X][BOARD_SIZE_Y];

    // Entity manipulation
    void addEntity(GameEntity *entity, int x, int y);
    void removeDeadEntities();

    int getLives();
    void setLives(int n);

    void addToScore(int n);
    int getScore();

    int getGameSpeed();

    int getGameTime();

    ~Game();
};