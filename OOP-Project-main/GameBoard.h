#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#include <SFML/Graphics.hpp>
#include <string>
#include "Menu.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Zombie.h"
#include "Ghost.h"
#include <cstddef>
#include <unistd.h>

using namespace std;

class GameBoard{
    private:
        sf::RenderWindow* win;
        Entity** Party;
        Entity** Enemys;
        Menu** menu_list;
        Menu* current_menu;

        int party_count;
        int enemy_count;
        int Difficulty;
        double difficulty_multiplier;
        int turn_counter;
        int current_turn;
        int dead_enemies;
        int dead_players;
    public:
        //GameBoard();
        GameBoard(int size_x,int size_y,std::string title);
        void draw_frame();
        void run();
        void increment_turn();
        ~GameBoard();
};


#endif // __GAMEBOARD_H__