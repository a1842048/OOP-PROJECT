#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Entity.h"

class Player : public Entity {
    private:
        int skill;
        Entity *enemy;

    public:
        Player(int health, int max_health, int damage, std::string name,std::string type);
        Player();
        ~Player();
        void attack(int skill, Entity *e);
        void attack(Entity *e);
        int get_input();
        Entity *get_enemy();
        virtual void call_block(bool decision) = 0;
        virtual int get_mana() = 0;
        virtual void castSpell(Entity *opponent) = 0;
        virtual int generate_action();
        void take_damage(int damage);

};

#endif
