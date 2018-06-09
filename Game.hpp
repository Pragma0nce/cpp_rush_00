#pragma once
#include "Tile.hpp"
#include "GameEntity.hpp"

const int BOARD_SIZE_X = 50;
const int BOARD_SIZE_Y = 10;

class Game
{
private:
    GameEntity **m_entities;
    int m_num_entities;
    int m_max_entities;
    bool m_running;
public:
    Game();

    void init();
    void update();
    void render();
    void processInput(int ch);

    bool isRunning();
    void stopRunning();

    Tile board[BOARD_SIZE_X][BOARD_SIZE_Y];

    // Entity manipulation
    void addEntity(GameEntity *entity, int x, int y);
};