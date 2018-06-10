#pragma once

class Game;

#define DEFAULT_PAIR     1
#define BULLET_PAIR      2
#define PLAYER_PAIR      3

enum ENTITY_TYPE
{
    PLAYER,
    ENEMY,
    COLLIDABLE,
    PROJECTILE
};

class GameEntity
{
protected:
    char m_sprite;

    int m_colorPair;

    ENTITY_TYPE m_type;

    int m_moveSpeed;
    int m_x;
    int m_y;

    bool m_alive;
public:
    GameEntity();
    GameEntity(char sprite, ENTITY_TYPE type);

    virtual void update(Game *world, int time);
    virtual void processInput(Game *world, int input);

    char getSprite();
    ENTITY_TYPE getType();

    bool move(Game *world, int x, int y);
    void moveLeft(Game *world);
    void moveRight(Game *world);
    void moveUp(Game *world);
    void moveDown(Game *world);

    bool checkCollision(Game *world, int x, int y);
    virtual void resolveCollision(Game *world, GameEntity *other);

    int getPosX();
    int getPosY();
    void setPosition(int x, int y);

    bool isAlive();
    void die();

    int getColorPair();
};