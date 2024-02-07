#include "Save.h"

using namespace std;

void Save::WriteSave(GameBoard *GameBoard) {
  // Fetching important runtime info from GameBoard
  Player **party_list = GameBoard->get_party();
  int party_count = GameBoard->get_party_count();
  Enemy **enemy_list = GameBoard->get_enemys();
  int enemy_count = GameBoard->get_enemy_count();

  // Setting up File Writing
  ofstream game_state;
  game_state.open("game_state.txt");

  if (game_state.is_open()) {
    game_state << "Valid Save:\n1\n"
               << "Party Count:\n"
               << party_count << "\n";

    // Iterating through Party & enemies Lists to fetch info
    // need to make if statement for alternate subclasses
    for (int i = 0; i < party_count; i++) {
      game_state << "Player " << i << " Class:\n"
                 << party_list[i]->get_class() << "\nPlayer " << i << " HP:\n"
                 << party_list[i]->get_health() << "\nPlayer " << i
                 << " Max HP:\n"
                 << party_list[i]->get_max_health() << "\nPlayer " << i
                 << " Damage:\n"
                 << party_list[i]->get_damage() << "\nPlayer " << i
                 << " Name:\n"
                 << party_list[i]->get_name() << "\n";
      if (party_list[i]->get_class() == "Wizard") {
        game_state << "Player " << i << " Mana:\n" << party_list[i]->get_mana();
      }
    }
    game_state << "Enemy Count:\n" << enemy_count;
    for (int i = 0; i < enemy_count; i++) {
      game_state << "Enemy " << i << "Class:\n"
                 << enemy_list[i]->get_class() << "\nEnemy " << i << " HP:\n"
                 << enemy_list[i]->get_health() << "\nEnemy " << i
                 << " Max HP:\n"
                 << enemy_list[i]->get_max_health() << "\nEnemy " << i
                 << " Damage:\n"
                 << enemy_list[i]->get_damage() << "\nEnemy " << i << " Name:\n"
                 << enemy_list[i]->get_name() << "\n";
    }
    game_state.close();
  }
}

bool Save::ReadSave(GameBoard *Gameboard) {

  ifstream game_state;
  game_state.open("game_state.txt");
  if (!game_state.is_open()) {
    return false;
  }
  // checking save validity
  int save_validity;
  std::string line;
  getline(game_state, line);
  getline(game_state, line);
  save_validity = stoi(line);
  if (!save_validity) {
    return false;
  }
  // Building Party List

  getline(game_state, line);
  getline(game_state, line);
  int count = stoi(line);
  Player **party_list = new Player *[count];
  Gameboard->set_party_count(count);
  for (int i = 0; i < Gameboard->get_party_count(); i++) {
    getline(game_state, line);
    getline(game_state, line);
    std::string type = line;
    getline(game_state, line);
    getline(game_state, line);
    int HP = stoi(line);
    getline(game_state, line);
    getline(game_state, line);
    int HP_max = stoi(line);
    getline(game_state, line);
    getline(game_state, line);
    int damage = stoi(line);
    getline(game_state, line);
    getline(game_state, line);
    std::string name = line;
    if (type == "Warrior") { // Warrior
      party_list[i] = new Warrior(HP, HP_max, damage, name);
    } else { // Wizard
      getline(game_state, line);
      getline(game_state, line);
      int mp = stoi(line);
      party_list[i] = new Wizard(HP, HP_max, damage, name, mp);
    }
  }

  // enemy list
  getline(game_state, line);
  getline(game_state, line);

  Enemy **enemy_list = new Enemy *[stoi(line)];
  Gameboard->set_enemy_count(stoi(line));
  for (int i = 0; i < Gameboard->get_party_count(); i++) {
    getline(game_state, line);
    getline(game_state, line);
    std::string type = line;
    getline(game_state, line);
    getline(game_state, line);
    int HP = stoi(line);
    getline(game_state, line);
    getline(game_state, line);
    int HP_max = stoi(line);
    getline(game_state, line);
    getline(game_state, line);
    int damage = stoi(line);
    getline(game_state, line);
    getline(game_state, line);
    std::string name = line;
    if (type == "Zombie") { // Zombie
      enemy_list[i] = new Zombie(HP, HP_max, damage, name, .5);
    } else { // Ghost
      enemy_list[i] = new Ghost(HP, HP_max, damage, name, .5);
    }
    Gameboard->set_party(party_list);
    Gameboard->set_enemies(enemy_list);
    game_state.close();
  }
  return true;
}

void Save::InvalidateSave() {
  // Invalidates the current game save, to be used when game ends so that the
  // user cannot reuse a save state

  ofstream game_state;
  game_state.open("game_state.txt");

  if (game_state.is_open()) {
    game_state << "Valid Save:\n0\n";
    game_state.close();
  }
}
