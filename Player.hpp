#pragma once
#include "GameEntity.hpp"
#include "Timer.hpp"

class Player : public GameEntity 
{
private:    
    Timer m_shootTimer;
protected:
    Player();
    Player(Player &other);
    Player& operator=(const Player& other);
public:
    Player(char sprite, ENTITY_TYPE type);
    void update(Game *world, int time);
    void processInput(Game *world, int input);

    void resolvecollision(Game *world);
    void takeDamage(Game *world);

    void shootRight(Game *world);

    ~Player();
};