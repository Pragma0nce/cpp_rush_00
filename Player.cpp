#include "Player.hpp"
#include <iostream>
#include <ncurses.h>
#include "Game.hpp"
#include "Projectile.hpp"


void Player::update(Game *world)
{
    GameEntity::update(world);
}

void Player::resolvecollision(Game *world)
{

}

void Player::processInput(Game *world, int input)
{
    if (input == 27)
    {
        world->stopRunning();
    }

    switch(input)
    {
        case (KEY_DOWN): moveDown(world); break;
        case (KEY_UP): moveUp(world); break;
        case (KEY_RIGHT): moveRight(world); break;
        case (KEY_LEFT): moveLeft(world); break;
        case (32): shootRight(world);
    }

}

void Player::shootRight(Game *world)
{
    Projectile *bullet = new Projectile('-', PROJECTILE);
    bullet->setDirection(1);

    world->addEntity(bullet, m_x + 1, m_y);
    std::cout << "shit" << std::endl;
}

Player::Player(char sprite, ENTITY_TYPE type)
:GameEntity(sprite, type)
{

}