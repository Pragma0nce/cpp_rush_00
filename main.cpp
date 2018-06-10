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
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);

    Game game;

    game.init();

    Player *player = new Player('>', PLAYER);
    game.addEntity(player, 1, 1);

    // Enemy *enemy1 = new Enemy('(', ENEMY);
    // Enemy *enemy2 = new Enemy('(', ENEMY);
    // Enemy *enemy3 = new Enemy('(', ENEMY);
    // game.addEntity(enemy1, 80, 5);
    // game.addEntity(enemy2, 70, 4);
    // game.addEntity(enemy3, 55, 8);

    int ch;
    int time = 0;

    while (game.isRunning())
    {
        usleep(game.getGameSpeed());
          if ((ch = getch()) == ERR) {
              /* user hasn't responded
               ...
              */
          }
          else {
            game.processInput(ch);
          }   
        game.update(time);
        game.render();
        time++;

        if (time > 10)
        {
            time = 0;
        }
    }
    endwin();
    std::cout << "Final score: " << game.getScore() << std::endl;
}