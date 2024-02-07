#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Entity {
 protected:
  int health;
  int max_health;
  int damage;
  string name;

 public:
  Entity(int h, int mh, int d, string n)
      : health(h), max_health(mh), damage(d), name(n) {}
  int get_health() const { return health; }
  void set_health(int h) { health = h; }
  int get_max_health() const { return max_health; }
  int get_damage() const { return damage; }
  void set_damage(int d) { damage = d; }
  virtual void attack(Entity* e) = 0;
  virtual void take_damage(int d) = 0;
};

class Player : public Entity {
 public:
  Player(int h, int mh, int d, string n) : Entity(h, mh, d, n) {}

  void attack(Entity* e) {
    int damage = get_damage();
    cout << "You attack " << e->name << " for " << damage << " damage!" << endl;
    e->take_damage(damage);
  }
  void take_damage(int d) {
    // 0 or 1 (true or false)
    int block_chance = rand() % 2;
    if (block_chance == 1) {
      // reduce random 1-5 damage
      int block_amount = rand() % 5 + 1;
      cout << "You block " << block_amount << " damage!" << endl;
      d -= block_amount;
      if (d < 0) {
        d = 0;
      }
    }
    set_health(get_health() - d);
    cout << "You take " << d << " damage!" << endl;
  }
  void get_input() {
    // Code to get input from the player
  }
};

class Enemy : public Entity {
 public:
  Enemy(int h, int mh, int d, string n) : Entity(h, mh, d, n) {}
  void attack(Entity* e) {
    int damage = get_damage();
    cout << name << " attacks you for " << damage << " damage!" << endl;
    e->take_damage(damage);
  }
  void take_damage(int d) {
    set_health(get_health() - d);
    cout << name << " takes " << d << " damage!" << endl;
  }
  virtual void generate_action() {
    // Code to generate a random action for the enemy
  }
};

class Warrior : public Player {
 private:
  double block_reduction;

 public:
  Warrior(int h, int mh, int d, string n, double br)
      : Player(h, mh, d, n), block_reduction(br) {}
  void block() {
    int block_chance = rand() % 2;
    if (block_chance == 1) {
      int block_amount = rand() % 5 + 1;
      cout << "You block " << block_amount << " damage!" << endl;
      block_reduction = (double)block_amount / 100;
    }
  }
  void attack(Entity* e) {
    int damage = get_damage();
    if (block_reduction > 0) {
      damage *= (1 - block_reduction);
      block_reduction = 0;
    }
    cout << "You attack " << e->name << " for " << damage << " damage!" << endl;
    e->take_damage(damage);
  }
};
class Wizard : public Player {
 public:
  Wizard(int h, int mh, int d, string n) : Player(h, mh, d, n) {}
  void attack(Entity* e) {
    int damage = get_damage() * 2;
    cout << "You cast a powerful spell and deal " << damage << " damage to "
         << e->name << "!" << endl;
    e->take_damage(damage);
  }
};

class Ghost : public Enemy {
 public:
  Ghost(int h, int mh, int d, string n) : Enemy(h, mh, d, n) {}
  void generate_action() {
    // Code to generate a random action for the ghost
  }
};

class Zombie : public Enemy {
 public:
  Zombie(int h, int mh, int d, string n) : Enemy(h, mh, d, n) {}
  void generate_action() {
    // Code to generate a random action for the zombie
  }
};

class Spell {
 protected:
  int mana_cost;

 public:
  Spell(int mc) : mana_cost(mc) {}
  virtual void cast(Entity* caster, Entity* target) = 0;
};

// Example of a specific spell
class Fireball : public Spell {
 public:
  Fireball(int mc) : Spell(mc) {}
  void cast(Entity* caster, Entity* target) {
    if (caster->get_mana() >= mana_cost) {
      int damage = 20;  // Assuming a fixed damage for simplicity
      cout << "You cast a fireball and deal " << damage << " damage to "
           << target->name << "!" << endl;
      target->take_damage(damage);
      caster->set_mana(caster->get_mana() - mana_cost);
    } else {
      cout << "Not enough mana to cast Fireball!" << endl;
    }
  }
};

int main() {
  

  srand(time(0));  // Initialize random seed

  Warrior player(100, 100, 10, "Player1", 0.1);
  Ghost enemy(50, 50, 8, "Ghost1");
  Fireball fireball(20);

  player.attack(&enemy);
  enemy.attack(&player);
  player.block();
  player.attack(&enemy);
  player.attack(&enemy);
  fireball.cast(&player, &enemy);

  return 0;
}