#include "Enemy.h"
#include "Entity.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstdlib>

//contructors and destructor
Enemy::Enemy(int health, int max_health, int damage, std::string name, std::string type)
    : Entity(health, max_health, damage, name, type){};

Enemy::Enemy() : Entity(){};

Enemy::~Enemy(){}

// randomise the enemy actions
int Enemy::generate_action()
{
    int key = rand() % 2;
    return key;
}

// two attacking function bottom one is for players and above is for the enemy
void Enemy::attack(Entity *e)
{
    this->enemy = e;
    int damageDealth = get_damage();
    std::cout << name << " attack " << e->get_name() << " for " << damageDealth << " damage." << std::endl;
    e->take_damage(damageDealth);
}

void Enemy::attack(int skill, Entity *e)
{
    this->skill = skill;
    this->enemy = e;
    int damageDealth = get_damage();
    std::cout << name << " attack " << e->get_name() << " for " << damageDealth << " damage." << std::endl;
    e->take_damage(damageDealth);
}

// Logic for dealing damage and dying
void Enemy::take_damage(int damage)
{
    set_health(get_health() - damage);
    if (get_health() <= 0) {
      std::cout << "Enemy is killed !!" << std::endl;
    }
  
}
