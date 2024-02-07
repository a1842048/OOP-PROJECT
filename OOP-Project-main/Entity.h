#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <iostream>

class Entity {
    protected:
        int health;
        int max_health;
        int damage;
        std::string name;
        std::string _class;
    public:
        Entity(int health, int max_health, int damage, std::string name, std::string type);
        Entity();

        int get_health()const;
        void set_health(int health);

        int get_max_health()const;

        int get_damage()const;
        void set_damage(int damage);

        std::string get_name()const;
        void set_name(std::string name);

        std::string get_class();

        virtual void attack(Entity *e) = 0;
        virtual void attack(int skill, Entity *e) = 0;

        virtual void take_damage(int damage) = 0;
        virtual int generate_action() = 0;

        virtual ~Entity(){};

};

#endif