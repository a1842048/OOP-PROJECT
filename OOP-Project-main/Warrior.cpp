#include "Warrior.h"

//constructors and destructor
Warrior::Warrior(int health, int max_health, int damage, std::string name)
    : Player(health, max_health, damage, name, "Warrior"){};

Warrior::Warrior() : Player(){};
Warrior::~Warrior(){};

//getter and setter
double Warrior::get_block_reduction() 
{ 
    return block_reduction; 
}

void Warrior::set_block_reduction(double block_reduction) 
{
    this->block_reduction = block_reduction;
}


void Warrior::call_block(bool decision) 
{
    blocked = decision; 
}

// logic for blocking damage dealt from enemy
void Warrior::block() 
{
    block_reduction = rand() % 20;
    std::cout << "You have blocked " << block_reduction << " damage."
              << std::endl;
}

void Warrior::attack(Entity *e) 
{
    int damageDealth = get_damage();
    std::cout << name << " attack " << e->get_name() << " for " << damageDealth
              << " damage." << std::endl;
    e->take_damage(damageDealth);
}

void Warrior::attack(int skill, Entity *e) 
{
    this->skill = skill;
    this->enemy = e;
    std::cout << "Incorrect attack call for warrior\n";
}

// logic for blocking and taking damage for Warrior
void Warrior::take_damage(int damage) 
{
    if (blocked) {
      block();
      call_block(false);
    }
    int damageDealt = damage;
    if (block_reduction > 0) {
      damageDealt -= block_reduction;
      if (damageDealt < 0) {
        damageDealt = 0;
      }
    }

    set_health(get_health() - damageDealt);
    std::cout << "Warrior Remaining Health: " << health << std::endl;
    if (get_health() <= 0) {
      std::cout << "Warrior " << name << " died!" << std::endl;
    }

    std::cout << std::endl;
}

// These functions are not available in Warrior
int Warrior::get_mana() 
{
    std::cout << "Mana called for warrior" << std::endl;
    return 0;
}

void Warrior::castSpell(Entity *opponent) 
{
    this->enemy = opponent;
    std::cout << "Spell called for warrior" << std::endl;
}

int Warrior::generate_action() 
{ 
    return 0; 
}