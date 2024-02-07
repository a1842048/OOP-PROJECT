//#include "GameBoard.h"
#include "ActionHandler.h"
#include "iostream"

int main(){
    GameBoard* game = new GameBoard(1600,1000, "Game");
    ActionHandler::set_gameBoard(game);
    game->run();

    delete game;
    return 0;
}