#include <stdlib.h>  // for rand() and srand()
#include <time.h>    // for time()
#include <vector>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Spell.h"

using namespace std;
int main() {
  // Wizard(name, health, damage, mana)
  Wizard wizard(100, 100, 20, "Melodias", 100);
  // Warrior(name, health, damage, weapon)
  Warrior warrior(150, 150, 30, "Grim");
  cout << "Let the battle begin!" << endl;
  
  wizard.print_spell();


  while (wizard.get_health() > 0 && warrior.get_health() > 0 ) {

    if (wizard.get_mana() <= 0){
      wizard.attack( &warrior);
    } else {
      wizard.castSpell( &warrior);
    }
    
    if (warrior.get_health() > 0) {
      warrior.call_block(true);
      warrior.attack( &wizard);
      
    }
  }

  if (wizard.get_health() > 0) {
    cout << wizard.get_name() << " wins!" << endl;
  } else {
    cout << warrior.get_name() << " wins!" << endl;
  }
  std::cout << std::endl;
  return 0;
}