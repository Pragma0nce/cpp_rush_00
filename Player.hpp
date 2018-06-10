#pragma once
#include "GameEntity.hpp"

class Player : public GameEntity 
{
private:
protected:
    Player();
    Player(Player &other);
public:
    Player(char sprite, ENTITY_TYPE type);
    void update(Game *world, int time);
    void processInput(Game *world, int input);

    void resolvecollision(Game *world);
    void takeDamage(Game *world);

    void shootRight(Game *world);

    ~Player();
};