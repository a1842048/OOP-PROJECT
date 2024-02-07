#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <SFML/Graphics.hpp>
#include <string>


#include "Entity.h"
//#include "Player.h"
#include "EntitySprite.h"

using namespace std;

class Button{
    private:
        int _x;
        int _y;
        float _width;
        float _height;

        string _name;
        string _type;
        string _action;
        bool _selected;
        sf::RectangleShape* body;
        sf::Text info;
        sf::Font font;

        sf::Color fill_color;


        Entity* _entity;
        EntitySprite* sprite;
    public:
        Button();
        Button(int x, int y, float width, float height, string name, string action, string type);
        Button(int x, int y, float width, float height, string name, string action, string type, Entity* entity);

        void action();
        void selected();
        void unselected();

        void draw(sf::RenderWindow* win);

        ~Button();
};


#endif // __BUTTON_H__