#ifndef SAVE_H
#define SAVE_H

// #include "Enemy.h"
// #include "Entity.h"
#include "GameBoard.h"
// #include "Ghost.h"
// #include "Player.h"
// #include "Warrior.h"
// #include "Wizard.h"
// #include "Zombie.h"
#include <fstream>
#include <iostream>

class Save {
public:
  static void WriteSave(GameBoard *GameBoard);
  static bool ReadSave(GameBoard *GameBoard);
  static void InvalidateSave();
};

#endif
