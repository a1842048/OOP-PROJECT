#include <stdlib.h>  // for rand() and srand()
#include <time.h>    // for time()

#include <iostream>
#include <vector>

#include "Enemy.h"
#include "Entity.h"
#include "Ghost.h"
#include "Player.h"
#include "Spell.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Zombie.h"

using namespace std;
int main() {
  // Wizard(name, health, damage, mana)
  Wizard wizard(100, 100, 20, "Melodias", 100);
  // Warrior(name, health, damage, weapon)
  Warrior warrior(150, 150, 30, "Grim");
  Zombie zombie(70, 70, 15, "Zombie", 10);
  Ghost ghost(100, 100, 10, "Ghost", 15);
  cout << "Let the battle begin!" << endl;

  wizard.print_spell();
  std::cout << std::endl;

  while (wizard.get_health() > 0 && warrior.get_health() > 0 &&
         zombie.get_health() > 0) {
    if (wizard.get_mana() <= 0) {
      wizard.attack(&zombie);
    } else {
      wizard.castSpell(&zombie);
    }

    if (zombie.get_health() > 0) {
      warrior.call_block(true);
      warrior.attack(&zombie);
    }

    if (zombie.get_health() > 0) {
      zombie.attack(&wizard);
      zombie.attack(&warrior);
    }
  }

  std::cout << "----------------------------------ROUND 2----------------------------------" << std::endl;

  while (wizard.get_health() > 0 && warrior.get_health() > 0 &&
         ghost.get_health() > 0) {
    if (wizard.get_mana() <= 0) {
      wizard.attack(&ghost);
    } else {
      wizard.castSpell(&ghost);
    }

    if (ghost.get_health() > 0) {
      warrior.call_block(true);
      warrior.attack(&ghost);
    }
    if (ghost.get_health() > 0) {
      ghost.attack(&wizard);
      ghost.attack(&warrior);
    }
  }
  std::cout << "#########################################################################" << std::endl;
  if (wizard.get_health() > 0 || warrior.get_health() > 0) {
    cout << "Players win!!" << endl;
  } else {
    cout << "Enemy wins!" << endl;
  }
  std::cout << std::endl;
  return 0;
}