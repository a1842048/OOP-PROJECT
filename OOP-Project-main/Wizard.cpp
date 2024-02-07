#include <unistd.h>
#include <random>
#include <string>
#include <vector>

#include "Player.h"
#include "Spell.h"
#include "Wizard.h"

//constructors and destructor
Wizard::Wizard(int health, int max_health, int damage, std::string name,
               int mana)
       : Player(health, max_health, damage, name, "Wizard"), mana(mana) 
{
    // creating the spell list 
    std::string spells[4] = {"Fireball", "Chill Touch", "Magic Missile",
                             "Lightning Bolt"};
    int cost[4] = {10, 25, 50, 100};

    for (int i = 0; i < 4; i++) {
        Spell *spell = new Spell(spells[i], cost[i]);
        spell_list.push_back(spell);
    }

};

Wizard::Wizard() : Player(), mana(0){};
Wizard::~Wizard(){};

int Wizard::get_mana() 
{ 
  return mana; 
}

void Wizard::set_mana(int mana) { 
  this->mana = mana; 
}

// Not available for Wizard
void Wizard::attack(int skill, Entity *e) 
{    
    this->skill = skill;
    this->enemy = e;
    std::cout << "Incorrect attack call for wizard\n";
}

void Wizard::attack(Entity *e) 
{
    int damageDealth = get_damage();
    std::cout << name << " attack " << e->get_name() << " for " << damageDealth
              << " damage." << std::endl;
    e->take_damage(damageDealth);
}

// Logic for dealing damage and dying
void Wizard::take_damage(int damage) 
{
    set_health(get_health() - damage);
    std::cout << "Wizard Remaining Health: " << health << std::endl;

    if (get_health() <= 0) {
        std::cout << "Wizard " << name << " died!" << std::endl;
    }
    std::cout << std::endl;
}

Spell *Wizard::choose_spell(int index) 
{ 
    return spell_list[index]; 
}

// logic for wizard spell casting
void Wizard::castSpell(Entity *opponent) 
{
    // std::random_device is a uniformly-distributed integer random number generator that produces non-deterministic random numbers
    std::random_device rd;  
    //random number generator

    std::mt19937 gen(rd());   
    // generate a random number from the distribution 

    std::uniform_int_distribution<> dis(0, 3); 
    // it gives this line to generate a number within the range of distribution 

    int key = dis(gen); 
    // it uses the code above to generate a number form the distribution

    Spell *spell = choose_spell(key);
    int damageDealt = spell->get_damage();

    if(damageDealt > this->mana){
        damageDealt = 0;
        std::cout << "Not enough mana" << std::endl;
    }

    this->mana = this->mana - damageDealt;

    std::cout << this->get_name() << " casts " << spell->get_name() << " on "
              << opponent->get_name() << " for " << damageDealt
              << " damage. Remaining mana: " << get_mana() << " \n";

    opponent->take_damage(damageDealt);
}

// Wizard cant block
void Wizard::call_block(bool decision) 
{
    blocked = decision;
    std::cout << "Block called for wizard, invalid" << std::endl;
}

// printing out the list of spells and damages
void Wizard::print_spell() 
{
    std::cout << "The Spell elements are : ";

    for (int i = 0; i < 4; i++) {
        std::cout << spell_list.at(i)->get_name() << ", ";
    }
    std::cout << std::endl;
    std::cout << "The Spell Damages are : ";
    for (int i = 0; i < 4; i++) {
        std::cout << spell_list.at(i)->get_damage() << ", ";
    }

    std::cout << std::endl;
}

// This is for Enemy class only
int Wizard::generate_action()
{ 
    return 0; 
}


std::vector<Spell *> Wizard::get_spell_list() 
{ 
    return spell_list; 
}
