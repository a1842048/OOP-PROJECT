#include "GameBoard.h"
#include "ActionHandler.h"
#include <string>
using namespace std;

GameBoard::GameBoard(int size_x,int size_y, std::string title)
{
    Party = new Entity*[2];
    Party[0] = new Wizard(100, 100, 20, "wizard", 100);
    Party[1] = new Warrior(200, 200, 80, "warrior");

    Enemys = new Entity*[4];
    Enemys[0] = new Zombie(100, 100, 50, "zombie1", 0.50);
    Enemys[1] = new Ghost(60, 60, 30, "ghost1", 0.5);
    Enemys[2] = new Zombie(100, 100, 50, "zombie2", 0.50);
    Enemys[3] = new Ghost(60, 60, 30, "ghost2", 0.5);

    menu_list = new Menu*[2];
    menu_list[0] = new Menu("main_menu", Party, Enemys);
    menu_list[1] = new Menu("wizard_menu", Party, Enemys);
    menu_list[2] = new Menu("warrior_menu", Party, Enemys);
    current_menu = menu_list[1];

    ActionHandler::set_menu(current_menu);
    win = new sf::RenderWindow(sf::VideoMode(size_x, size_y), title);

    party_count = 2;
    enemy_count = 4;
    Difficulty = 1;

    switch (Difficulty) {
    case 1:
        difficulty_multiplier = 0.9;
    break;
    case 2:
        difficulty_multiplier = 1.1;
    break;
    case 3:
        difficulty_multiplier = 1.3;
    break;
    }

    for (int i = 0; i < enemy_count; i++) {
        int new_damage = Enemys[i]->get_damage() * difficulty_multiplier;
        Enemys[i]->set_damage(new_damage);
    }

    turn_counter = 0;
    current_turn = 0;

    dead_enemies = 0;
    dead_players = 0;

}


void GameBoard::draw_frame()
{
    // current_menu->button_select();
    // cout << "ooooo" << endl;
    current_menu->draw(win);
} 

void GameBoard::run()
{
    // run the program as long as the window is open
    while (win->isOpen())
    {
        if(current_turn == 0) {
            current_menu = menu_list[1];
            ActionHandler::set_menu(current_menu);
            current_menu->set_turn_number(current_turn);
         }
        else if(current_turn == 1) {
            current_menu = menu_list[2];
            //cout << "ooooo" << endl;

            ActionHandler::set_menu(current_menu);
            current_menu->set_turn_number(current_turn);
            //cout << "GB 80" << endl;
        }
        else if(current_turn == 2) {
            for (int i = 0; i < enemy_count; i++) {
            // skip turn if entity is dead
                if (Enemys[i]->get_health() >= 0) {
                // Enemies can only attach, so the generate action is going to select a
            // player to be attacked.
                    Enemys[i]->attack(Party[Enemys[i]->generate_action()]);
                    //sleep(1);
            }else {
                dead_enemies++;
            }
            }
            current_turn = 0;
        }



        if (dead_players == party_count) {
            cout << "End Game" << endl;
        }


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (win->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                win->close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::Left){
                        current_menu->move_selected("left");
                }
                if(event.key.code == sf::Keyboard::Right){
                        current_menu->move_selected("right");
                }
                if(event.key.code == sf::Keyboard::Up){
                        current_menu->move_selected("up");
                }
                if(event.key.code == sf::Keyboard::Down){
                        current_menu->move_selected("down");
                }

                if(event.key.code == sf::Keyboard::Space){
                        current_menu->button_activate();
                }
            }
        }
        win->clear();
        draw_frame();
        win->display();
    }
    return;
}

void GameBoard::increment_turn()
{
    current_turn++;
    return;
}

GameBoard::~GameBoard()
{
    delete win;
    delete[] Party;
    delete[] Enemys;
    delete current_menu;
    delete menu_list;
}

// GameBoard::GameBoard()
// {
    
// }
