#ifndef GHOST_H
#define GHOST_H

#include "Enemy.h"
#include <iostream>

class Ghost : public Enemy {
    private:
        double physical_reduction;
        int skill;
        Entity *enemy;
    public:
        Ghost(int health, int max_health, int damage, std::string name, double physical_reduction);
        Ghost();
        double get_magic_reduction();
        double get_physical_reduction();
        void attack(Entity *e);
        void attack(int skill, Entity *e);
        void take_damage(int damage);
};

#endif
