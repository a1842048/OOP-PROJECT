#include "Player.h"
#include "Entity.h"
#include <iostream>
#include <string>

// constructor and destructor
Player::Player(int health, int max_health, int damage, std::string name,std::string type)
       : Entity(health, max_health, damage, name, type) {}

Player::Player() : Entity() {}
Player::~Player() {}

// logic for getting action and attacking enemy
void Player::attack(int skill, Entity *e) 
{
    this->skill = skill;
    this->enemy = e;
    int damageDealth = get_damage();
    std::cout << name << " attack " << e->get_name() << " for " << damageDealth << " damage." << std::endl;
    e->take_damage(damageDealth);
}

// logic for attacking enemy without action
void Player::attack(Entity *e) 
{
    this->enemy = e;
    int damageDealth = get_damage();
    std::cout << name << " attack " << e->get_name() << " for " << damageDealth << " damage." << std::endl;
    e->take_damage(damageDealth);
    return;
}

int Player::get_input()
{ 
    return skill; 
}

Entity *Player::get_enemy() 
{ 
    return enemy; 
}

int Player::generate_action() 
{ 
    return 0; 
}

void Player::take_damage(int damage)
{
    set_health(get_health() - damage);
    if (get_health() <= 0) {
        std::cout << "This player died!" << std::endl;
    }
}
