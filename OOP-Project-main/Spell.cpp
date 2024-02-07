#include "Spell.h"

Spell::Spell(std::string name, int damage)
{
    this->name = name;
    this->damage = damage;
    this->mana_cost = damage;
    // this->is_aoe = is_aoe;
}

Spell::Spell() : Spell("Name", 0) {}

std::string Spell::get_name()
{
    return name; 
}

int Spell::get_damage() 
{ 
    return damage; 
}
