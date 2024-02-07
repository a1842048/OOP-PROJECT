#ifndef __MENU_H__
#define __MENU_H__

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <string>

#include "Entity.h"
#include "Player.h"
#include "Button.h"

using namespace std;

class Menu {
    protected:
        Button*** buttonArray;
        vector<int>* valid_positions;
        vector<int> current_position;
        string _name;

        int _rows;
        int _cols;
        int num_valid_pos;

        //sf::Texture texture;
        sf::Sprite background;

        Entity** Party;
        Entity** Enemys;

        Entity* targeted_Enemy;
        int turn_number;
        
    public:
        Menu();
        Menu(string name, Entity** P, Entity** E);
        void move_selected(string direction);
        vector<int> get_pos();
        void check_pos(vector<int> new_pos);

        void button_activate();
        void button_unselect();
        void button_select();
        void change_position(vector<int> v);
        int current_selected();

        Entity* get_Enemy(vector<int> pos);
        void set_targeted(Entity* S);
        Entity* get_targeted();

        void set_turn_number(int turn);
        Entity* get_current_player();

        void draw(sf::RenderWindow* win);

        void main_menu();
        void wizard_menu();
        void warrior_menu();
        ~Menu(); 
};

static sf::Texture texture;




#endif // __MENU_H__