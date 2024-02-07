#include "ActionHandler.h"
#include <iostream>
#include <string>

using namespace std;

void ActionHandler::start()
{
    cout << "start" << endl;
}

void ActionHandler::difficultySelect()
{
    cout << "d_select" << endl;
}

void ActionHandler::quit()
{
    cout << "quit" << endl;
}

void ActionHandler::choose_target()
{
    vector<int> v1 = {0,0};
    current_menu->button_unselect();
    current_menu->change_position(v1);
}

void ActionHandler::set_menu(Menu* M)
{
    //delete current_menu;
    ActionHandler::current_menu = M;
}

void ActionHandler::set_gameBoard(GameBoard* G)
{
    //delete gameBoard;
    ActionHandler::gameBoard = G;
}

void ActionHandler::set_target()
{
    current_menu->button_unselect();
    vector<int> v1 = current_menu->get_pos();
    Entity* target = current_menu->get_Enemy(v1);
    current_menu->set_targeted(target);
    vector<int> v2 = {4,0};
    current_menu->change_position(v2);
}

void ActionHandler::attack()
{
    Entity* target = current_menu->get_targeted();
    (current_menu->get_current_player())->attack(current_menu->get_targeted());
    gameBoard->increment_turn();
}

void ActionHandler::choose_action(string action)
{
    if(action == "start"){
        ActionHandler::start();
    }
    else if(action == "d_select"){
        ActionHandler::difficultySelect();
    }
    else if(action == "quit"){
        ActionHandler::quit();
    }
    else if(action == "choose_target"){
        ActionHandler::choose_target();
    }
    else if (action == "enemy"){
        set_target();
    }
    else if (action == "attack"){
        attack();
        return;
    }
}

GameBoard* ActionHandler::gameBoard = nullptr;
Menu* ActionHandler::current_menu = nullptr;
