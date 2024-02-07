#include "Ghost.h"
#include "Enemy.h"
#include "Entity.h"

//contructor and destructor
Ghost::Ghost(int health, int max_health, int damage, std::string name, double physical_reduction)
      : Enemy(health, max_health, damage, name, "Ghost"),
      physical_reduction(physical_reduction){};

Ghost::Ghost() : Enemy(), physical_reduction(0) {}

double Ghost::get_physical_reduction() 
{ 
    return physical_reduction; 
}

void Ghost::attack(Entity *e)
{
    int damageDealth = get_damage() + get_physical_reduction();
    std::cout << name << " attack " << e->get_name() << " for " << damageDealth << " damage." << std::endl;
    e->take_damage(damageDealth);
}

// only available in Player class
void Ghost::attack(int skill, Entity *e)
{ 
    this->skill = skill;
    this->enemy = e;
    std::cout << "incorrect attack call for Ghost\n";
}

// Logic for Ghost taking damage and dying
void Ghost::take_damage(int damage) 
{
    set_health(get_health() - damage);
    std::cout << "Ghost Remaining Health: " << health << std::endl;
    if (get_health() <= 0) {
        std::cout << "Ghost is killed !!" << std::endl;
    }
    std::cout << std::endl;
}
