#ifndef __ENTITYSPRITE_H__
#define __ENTITYSPRITE_H__

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <string>

#include "Player.h"
#include "Entity.h"

#include <iostream>
using namespace std;


class EntitySprite {
    private:
        int _x;
        int _y;
        Entity* _entity;
        string _type;

        double max_health;
        double current_health;

        sf::Texture image;
        sf::Sprite sprite;

        sf::RectangleShape* max_health_bar;
        sf::RectangleShape* current_health_bar;
    public:
        EntitySprite();
        EntitySprite(int x, int y, Entity* entity, string type);

        void draw(sf::RenderWindow* win);
        
        ~EntitySprite();
};



#endif // __ENTITYSPRITE_H__