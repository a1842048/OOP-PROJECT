#include "Zombie.h"

#include "Enemy.h"
#include "Entity.h"
#include "Wizard.h"

//contructor and destructor
Zombie::Zombie(int health, int max_health, int damage, std::string name,
               double magic_reduction)
    : Enemy(health, max_health, damage, name, "Zombie"),
      magic_reduction(magic_reduction){};

Zombie::Zombie() : Enemy(), magic_reduction(0) {}
Zombie::~Zombie() {}

double Zombie::get_magic_reduction() { return magic_reduction; }

void Zombie::attack(Entity *e) {
  int damageDealth = get_damage();
  if (e->get_name() == "Wizard") {
    // e->set_mana(e->get_mana() - get_magic_reduction());
  }
  std::cout << name << " attack " << e->get_name() << " for " << damageDealth
            << " damage." << std::endl;
  e->take_damage(damageDealth);
}

void Zombie::attack(int skill, Entity *e) {
  this->skill = skill;
  this->enemy = e;
  std::cout << "incorrect attack call for zombie\n";
}

// Logic for Zombie taking damage and dying
void Zombie::take_damage(int damage) {
  set_health(get_health() - damage);
  std::cout << "Zombie Remaining Health: " << health << std::endl;
  if (get_health() <= 0) {
    std::cout << "Zombie died!" << std::endl;
  }
  std::cout << std::endl;
}
