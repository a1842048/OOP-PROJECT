#ifndef WARRIOR_H
#define WARRIOR_H
#include "Entity.h"
#include "Player.h"
#include <iostream>

class Warrior : public Player {
    private:
        double block_reduction;
        int damageDealt;
        bool blocked = false;
        int skill;
        Entity *enemy;

    public:
        Warrior(int health, int max_health, int damage, std::string name);
        Warrior();
        ~Warrior();
        double get_block_reduction();
        void set_block_reduction(double block_reduction);
        void call_block(bool decision);
        void block();
        void attack(Entity *e);
        void attack(int skill, Entity *e);
        void take_damage(int damage);
        int generate_action();
        int get_mana();
        void castSpell(Entity *opponent);
};

#endif
