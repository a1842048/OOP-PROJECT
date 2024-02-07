#include "Enemy.h"
#include "Entity.h"
#include "Player.h"
#include "Warrior.h"
#include "Wizard.h"
#include <cstddef>
#include <string>
#include <unistd.h>

// placeholder classes to stop the IDE marking everything as red

class GameBoard {
private:
  int party_count;
  int enemy_count;

public:
  int get_party_count();
  int get_enemy_count();
  Enemy **get_enemys();
  Player **get_party();
};

// Combat loop will have different states based off of difficulty
// will return a true for a win or a false for a loss

bool CombatLoop(int Difficulty, GameBoard *GameBoard) {
  /* The game_state variable will be used to check the living state of entities
  and as a failsafe in case I forget to break the loop at any given point,
  this should switch to false at the point that all player classes die or
  all enemy classes die */
  bool game_state = true;
  // Stat Multipliers!
  double difficulty_multiplier = 0.0;
  switch (Difficulty) {
  case 1:
    difficulty_multiplier = 0.9;
    break;
  case 2:
    difficulty_multiplier = 1.1;
    break;
  case 3:
    difficulty_multiplier = 1.3;
    break;
  }

  // Getting access to the party and enemy lists out of the GameBoard
  Player **party_list;
  Enemy **enemy_list;

  party_list = GameBoard->get_party();
  enemy_list = GameBoard->get_enemys();

  // Adjusting damage for all enemies based off of difficulty selected
  for (int i = 0; i < GameBoard->get_enemy_count(); i++) {
    int new_damage = enemy_list[i]->get_damage() * difficulty_multiplier;
    enemy_list[i]->set_damage(new_damage);
  }

  // Starting the gameplay loop

  int turn_counter = 0;

  while (game_state) {

    int dead_enemies = 0;
    int dead_players = 0;

    // Player Turn Loop
    for (int i = 0; i < GameBoard->get_party_count(); i++) {
      // skip turn if entity is dead
      if (party_list[i]->get_health() >= 0) {

        switch (party_list[i]->get_input()) {
          // attack case
        case 1:
          party_list[i]->attack(party_list[i]->get_enemy());
          break;
          // Block Case
        case 2:
          party_list[i]->call_block(true);
          break;
          // Case 3
        case 3:
          party_list[i]->castSpell(party_list[i]->get_enemy());
          break;
        case 4:
          break;
        }
      } else {
        dead_players++;
      }
    }

    // If all players in game are dead, return false (Game Lost)
    if (dead_players == GameBoard->get_party_count()) {
      return false;
    }
    // Block logic to calculate temp health before enemy turn takes place

    // Enemy Turn Loop
    for (int i = 0; i < GameBoard->get_enemy_count(); i++) {
      // skip turn if entity is dead
      if (enemy_list[i]->get_health() >= 0) {
        // Enemies can only attach, so the generate action is going to select a
        // player to be attacked.

        enemy_list[i]->attack(party_list[enemy_list[i]->generate_action()]);
        sleep(1);
      } else {
        dead_enemies++;
      }
    }
    // Check to see if all enemies are dead, if so return true (game won)
    if (dead_enemies == GameBoard->get_enemy_count()) {
      return true;
    }

    // After the enemy turn, check block status and negate temp-health from
    // block
    turn_counter++;
  }
  return false;
}
