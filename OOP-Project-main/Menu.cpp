#include "Menu.h"
#include "GameBoard.h"
#include <iostream>
using namespace std;


Menu::Menu(string name, Entity** P, Entity** E)
{
    Party = P;
    Enemys = E;
    _name = name;
    if (name == "main_menu"){
        main_menu();
    }
    else if (name == "wizard_menu"){
        wizard_menu();
    }
    else if (name == "warrior_menu"){
        warrior_menu();
    }
    else{
        cout << "invalid menu type " << endl;
    }
    texture.loadFromFile("Background.psd");
    background.setTexture(texture);
    background.scale(sf::Vector2f(3.28, 3.3));

    targeted_Enemy = Enemys[0];
    turn_number = 0;
}

void Menu::move_selected(string direction)
{
    vector<int> new_pos = current_position;

    if(direction == "down"){
        new_pos[0]++;
        Menu::check_pos(new_pos);
    }

    if(direction == "up"){
        new_pos[0]--;
        Menu::check_pos(new_pos);
    }

    if(direction == "left"){
        new_pos[1]--;
        Menu::check_pos(new_pos);
    }
    if(direction == "right"){
        new_pos[1]++;
        Menu::check_pos(new_pos);
    }
}

vector<int> Menu::get_pos()
{
    return current_position;
}

void Menu::check_pos(vector<int> new_pos)
{
    for(int i = 0; i < num_valid_pos; i++){
        if(valid_positions[i] == new_pos){

            int Orow = current_position[0];
            int Ocol = current_position[1];
            buttonArray[Orow][Ocol]->unselected();

            current_position = new_pos; 

            int Nrow = new_pos[0];
            int Ncol = new_pos[1];
            buttonArray[Nrow][Ncol]->selected();
        }
    }
}

void Menu::button_activate()
{
    int row = current_position[0];
    int col = current_position[1];

    buttonArray[row][col]->action();
}

void Menu::button_select()
{
    int row = current_position[0];
    int col = current_position[1];

    buttonArray[row][col]->selected();
}

void Menu::change_position(vector<int> v)
{
    int row = current_position[0];
    int col = current_position[1];
    buttonArray[row][col]->unselected();

    current_position[0] = v[0];
    current_position[1] = v[1];
    buttonArray[v[0]][v[1]]->selected();
}

void Menu::button_unselect()
{
    int row = current_position[0];
    int col = current_position[1];

    buttonArray[row][col]->unselected();
}


int Menu::current_selected()
{
    return 0;
}

Entity* Menu::get_Enemy(vector<int> pos)
{
    return Enemys[pos[1]];
}

void Menu::set_targeted(Entity* S)
{
    targeted_Enemy = S;
}

Entity* Menu::get_targeted()
{
    return targeted_Enemy;
}

void Menu::set_turn_number(int turn)
{
    turn_number = turn;
}

Entity* Menu::get_current_player()
{
    return Party[turn_number];
}

void Menu::draw(sf::RenderWindow* win)
{
    win->draw(background);
    //cout << _rows << _cols << endl;
    for(int row = 0; row<_rows; row++){
        for(int col = 0; col<_cols; col++){

            vector<int> test = {row, col};
            for(int i = 0; i<num_valid_pos; i++){
                if(test == valid_positions[i]){ 
                    buttonArray[row][col]->draw(win);
                }
            }
        }
    }
    
}

void Menu::main_menu()
{
    std::cout << "main menu created" << endl;
    _rows = 3;
    _cols = 1;
    buttonArray = new Button**[_rows];
    for(int i = 0; i < _rows; i++){
        buttonArray[i] = new Button*[_cols];
    }

    buttonArray[0][0] = new Button(400, 100, 400, 200, "B1", "start", "menu");
    buttonArray[1][0] = new Button(400, 300, 400, 200, "B2", "d_select", "menu");
    buttonArray[2][0] = new Button(400, 500, 400, 200, "B3", "quit", "menu");

    num_valid_pos = 3;
    valid_positions = new vector<int>[num_valid_pos]; //array of vectors (not vector itself)
    valid_positions[0] = {0,0};
    valid_positions[1] = {1,0};
    valid_positions[2] = {2,0};

    current_position = {0,0};
    buttonArray[0][0]->selected();
}

void Menu::wizard_menu()
{
    std::cout << "wizard menu created" << endl;
    _rows = 5;
    _cols = 4;

    buttonArray = new Button**[_rows];
    for(int i = 0; i < _rows; i++){
        buttonArray[i] = new Button*[_cols];
    }


    buttonArray[0][0] = new Button(800, 600, 140, 200, "", "enemy", "entity", Enemys[0]);
    buttonArray[0][1] = new Button(1000, 600, 140, 200, "", "enemy", "entity", Enemys[1]);
    buttonArray[0][2] = new Button(1200, 600, 140, 200, "", "enemy", "entity", Enemys[2]);
    buttonArray[0][3] = new Button(1400, 600, 140, 200, "", "enemy", "entity", Enemys[3]);
    buttonArray[2][0] = new Button(50, 600, 140, 200, "", "player_1", "entity", Party[0]);
    buttonArray[2][1] = new Button(275, 600, 140, 200, "", "player_2", "entity", Party[1]);
    buttonArray[4][0] = new Button(5, 845, 400, 150, "    Attack", "attack", "menu");
    buttonArray[4][1] = new Button(400, 845, 400, 150, "  Cast Spell", "cast_spell", "menu");
    buttonArray[4][2] = new Button(800, 845, 400, 150, " Choose Spell", "choose_spell", "menu");
    buttonArray[4][3] = new Button(1195, 845, 400, 150, "Choose Target", "choose_target", "menu");

    num_valid_pos = 10;
    valid_positions = new vector<int>[num_valid_pos]; //array of vectors (not vector itself)
    valid_positions[0] = {0,0};
    valid_positions[1] = {0,1};
    valid_positions[2] = {0,2};
    valid_positions[3] = {0,3};
    valid_positions[4] = {2,0};
    valid_positions[5] = {2,1};
    valid_positions[6] = {4,0};
    valid_positions[7] = {4,1};
    valid_positions[8] = {4,2};
    valid_positions[9] = {4,3};

    current_position = {4,0};
    buttonArray[4][0]->selected();
    buttonArray[0][0]->unselected();
}

void Menu::warrior_menu()
{
    std::cout << "warrior menu created" << endl;
    _rows = 5;
    _cols = 4;

    buttonArray = new Button**[_rows];
    for(int i = 0; i < _rows; i++){
        buttonArray[i] = new Button*[_cols];
    }


    buttonArray[0][0] = new Button(800, 600, 140, 200, "", "enemy", "entity", Enemys[0]);
    buttonArray[0][1] = new Button(1000, 600, 140, 200, "", "enemy", "entity", Enemys[1]);
    buttonArray[0][2] = new Button(1200, 600, 140, 200, "", "enemy", "entity", Enemys[2]);
    buttonArray[0][3] = new Button(1400, 600, 140, 200, "", "enemy", "entity", Enemys[3]);
    buttonArray[2][0] = new Button(50, 600, 140, 200, "", "player_1", "entity", Party[0]);
    buttonArray[2][1] = new Button(275, 600, 140, 200, "", "player_2", "entity", Party[1]);
    buttonArray[4][0] = new Button(5, 845, 400, 150, "    Attack", "attack", "menu");
    buttonArray[4][1] = new Button(400, 845, 400, 150, "  Block", "block", "menu");
    buttonArray[4][2] = new Button(800, 845, 400, 150, "Choose Target", "choose_target", "menu");

    num_valid_pos = 9;
    valid_positions = new vector<int>[num_valid_pos]; //array of vectors (not vector itself)
    valid_positions[0] = {0,0};
    valid_positions[1] = {0,1};
    valid_positions[2] = {0,2};
    valid_positions[3] = {0,3};
    valid_positions[4] = {2,0};
    valid_positions[5] = {2,1};
    valid_positions[6] = {4,0};
    valid_positions[7] = {4,1};
    valid_positions[8] = {4,2};

    current_position = {4,0};
    buttonArray[4][0]->selected();
    buttonArray[0][0]->unselected();
}

Menu::~Menu()
{
    delete[] buttonArray;
    delete[] valid_positions;

}

Menu::Menu()
{
    return;
}
