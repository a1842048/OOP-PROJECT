#ifndef __ACTIONHANDLER_H__
#define __ACTIONHANDLER_H__

#include <string>
#include "Menu.h"
#include "GameBoard.h"
using namespace std;


class ActionHandler {
    private:
        static GameBoard* gameBoard;
        static Menu* current_menu;
    public:
        static void set_menu(Menu* M);
        static void set_gameBoard(GameBoard* G);

        static void start();
        static void difficultySelect();
        static void quit();
        static void choose_target();
        static void set_target();
        static void attack();

        static void choose_action(string action);

};

#endif // __ACTIONHANDLER_H__