#ifndef WIZARD_H
#define WIZARD_H

#include <string>
#include <vector>

#include "Player.h"
#include "Spell.h"

class Wizard : public Player {
    private:
        int mana;
        bool blocked = false;
        std::vector<Spell *> spell_list;
        int skill;
        Entity *enemy;

    public:
        Wizard(int health, int max_health, int damage, std::string name, int mana);
        Wizard();

        ~Wizard();

        int get_mana();
        void set_mana(int mana);

        void attack(int skill, Entity *e);
        void attack(Entity *e);

        void take_damage(int damage);

        Spell *choose_spell(int index);

        void castSpell(Entity *opponent);

        int generate_action();

        void call_block(bool decision);

        std::vector<Spell *> get_spell_list();
  
        void print_spell();
};

#endif
