#pragma once

class GameEntity;

class Tile 
{
private:
    char m_sprite;
    GameEntity *m_entity;
    bool m_empty;

protected:
    Tile(Tile &other);
    Tile& operator=(const Tile& other);
public:
    Tile();
    
    char getSprite();

    GameEntity *getEntity();
    void setEntity(GameEntity *entity);
    bool isEmpty();

    ~Tile();

};