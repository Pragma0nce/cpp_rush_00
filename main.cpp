#include <curses.h>
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include<unistd.h>

int main()
{
    //ncurses shit
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    Game game;

    game.init();

    Player player('P', PLAYER);
    game.addEntity(&player, 1, 1);

    Enemy enemy1('@', ENEMY);
    Enemy enemy2('@', ENEMY);
    Enemy enemy3('@', ENEMY);
    game.addEntity(&enemy1, 25, 1);
    game.addEntity(&enemy2, 29, 4);
    game.addEntity(&enemy3, 22, 9);

    int ch;
    while (game.isRunning())
    {
        usleep(60000);
          if ((ch = getch()) == ERR) {
              /* user hasn't responded
               ...
              */
          }
          else {
            game.processInput(ch);
          }   
        game.update();
        game.render();
    }

    endwin();
}