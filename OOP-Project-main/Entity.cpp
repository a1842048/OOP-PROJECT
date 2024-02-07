#include "Entity.h"
#include <string>
#include <iostream>

Entity::Entity(int health, int max_health, int damage, std::string name, std::string type) 
: health(health), max_health(max_health), damage(damage), name(name), _class(type) {}

Entity::Entity() : Entity(0,0,0,"No Name","No Class") {}

// getters and setters
int Entity::get_health() const
{
    return health;
}

void Entity::set_health(int health)
{
    this->health = health;
}

int Entity::get_max_health()const
{
    return max_health;
}

int Entity::get_damage()const
{
    return damage;
}

void Entity::set_damage(int damage)
{
    this->damage = damage;
}

std::string Entity::get_name()const
{
    return name;
}

void Entity::set_name(std::string name)
{
    this->name = name;
}

std::string Entity::get_class()
{
    return _class;
}


