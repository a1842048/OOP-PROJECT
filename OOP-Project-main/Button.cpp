#include "Button.h"
#include <iostream>
#include "ActionHandler.h"

Button::Button()
{
    std::cout << "Improper constructor" << endl;
}

Button::Button(int x, int y, float width, float height, string name, string action, string type)
{
    if(!font.loadFromFile("./font.ttf")){
            std::cout << "Font not fount\n";
            exit(0);
    }
    info.setFont(font);
    info.setFillColor(sf::Color(240, 242, 245));
    info.setCharacterSize(60);
    std::string txt;
    txt = name;
    info.setString(txt);

    _x = x;
    _y = y;
    _name = name;
    _action = action;

    _width = width;
    _height = height;
    body = new sf::RectangleShape(sf::Vector2f(width, height));
    body->setPosition(x, y);

    info.setPosition(x+45.f, y+30);

    _type = type;
    if(type == "menu"){
        fill_color = sf::Color(132, 138, 150);
        body->setFillColor(fill_color);
        body->setOutlineThickness(5.f);
        body->setOutlineColor(sf::Color(240, 242, 245));
    }
    else if(type == "entity"){
        body->setFillColor(sf::Color::Transparent);
    }
}

Button::Button(int x, int y, float width, float height, string name, string action, string type, Entity* entity) : Button(x,y,width,height,name,action,type)
{
    _entity = entity;
    sprite = new EntitySprite(x,y,entity,type);  
}
void Button::action()
{
   ActionHandler::choose_action(_action);
}

void Button::selected()
{
    _selected = true;
}

void Button::unselected()
{
    _selected = false;
    
}

void Button::draw(sf::RenderWindow* win)
{
    if(_type == "menu"){ 
        if(_selected == true){
            body->setFillColor(sf::Color(187, 190, 196));
        }
        else if(_selected == false){
            body->setFillColor(fill_color);
        }
    }
    else if(_type == "entity"){ 
        if(_selected == true){
            body->setOutlineThickness(5.f);
            body->setOutlineColor(sf::Color(187, 190, 196));
        }
        else if(_selected == false){
            body->setOutlineColor(sf::Color::Transparent);
        }

        sprite->draw(win);
    }


    win->draw(*body);
    win->draw(info);

}

Button::~Button()
{
    delete body;
    delete sprite;
}
