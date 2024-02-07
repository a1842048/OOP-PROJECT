#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Enemy.h"
#include <iostream>

class Zombie : public Enemy {
    private:
        double magic_reduction;
        int skill;
        Entity *enemy;
    public:
        Zombie(int health, int max_health, int damage, std::string name, double  magic_reduction);
        Zombie();
        ~Zombie();
        double get_magic_reduction();
        void attack(Entity *e);
        void attack(int skill, Entity *e);
        void take_damage(int damage);
};


#endif