#include "EntitySprite.h"


EntitySprite::EntitySprite(int x, int y, Entity* entity, string type)
{
    _x = x;
    _y = y;
    _entity = entity;
    _type = type;


    max_health = entity->get_max_health();
    current_health = entity->get_health();

    if(_entity->get_class() == "Warrior"){
        image.loadFromFile("Knight.png");
        sprite.setTexture(image);
        sprite.scale(sf::Vector2f(4, 4));
        sprite.setPosition(_x,_y);
    }
    else if(_entity->get_class() == "Wizard"){
        image.loadFromFile("Wizard.png");
        sprite.setTexture(image);
        sprite.scale(sf::Vector2f(2, 2));
        sprite.setPosition(_x-10,_y-15);
    }
    else if(_entity->get_class() == "Zombie"){
        image.loadFromFile("Zombie.png");
        sprite.setTexture(image);
        sprite.scale(sf::Vector2f(6, 6));
        sprite.setPosition(_x-20,_y+25);
    }
    else if(_entity->get_class() == "Ghost"){
        image.loadFromFile("Ghost.png");
        sprite.setTexture(image);
        sprite.scale(sf::Vector2f(3.5, 3.5));
        sprite.setPosition(_x-10,_y+20);
    }


    max_health_bar = new sf::RectangleShape(sf::Vector2f(140, 20));
    max_health_bar->setPosition(x, y);
    max_health_bar->setFillColor(sf::Color::Red);

    current_health_bar = new sf::RectangleShape(sf::Vector2f(140, 20));
    current_health_bar->setPosition(x, y);
    current_health_bar->setFillColor(sf::Color::Green);
}



void EntitySprite::draw(sf::RenderWindow* win)
{
    win->draw(sprite);

    max_health = _entity->get_max_health();
    current_health = _entity->get_health();
    double health_ratio = current_health/max_health;
    if(current_health < 0) {
        health_ratio = 0;
    }
    current_health_bar->setSize(sf::Vector2f(140*health_ratio,20));
    win->draw(*max_health_bar);
    win->draw(*current_health_bar);
}

EntitySprite::~EntitySprite()
{
    delete max_health_bar;
    delete current_health_bar;
}

EntitySprite::EntitySprite()
{
    cout << "default called oops" << endl;
}
