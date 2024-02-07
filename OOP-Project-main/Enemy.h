#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>

#include "Entity.h"

class Enemy : public Entity {
    private:
        int skill;
        Entity *enemy;

    public:
        Enemy(int health, int max_health, int damage, std::string name, std::string type);
        Enemy();
        ~Enemy();
        int generate_action();
        void attack(Entity *e);
        void attack(int skill, Entity *e);
        void take_damage(int damage);
};

#endif
