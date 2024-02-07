#ifndef SPELL_H
#define SPELL_H

#include <string>

class Spell {
    private:
        std::string name;
        int damage;
        // bool is_aoe; //specify if single or multiple target for damage
        int mana_cost;

    public:
        Spell(std::string name, int damage);
        Spell();
        std::string get_name();
        int get_damage();
};

#endif
