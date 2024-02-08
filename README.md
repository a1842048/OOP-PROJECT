# OOP-Project
It's an RPG game thats a single player where the player will be assigned to a Warrior and Wizard.
and tasked to defeat a group of enemies based on the difficulty chosen.
# Installation
-> Install [SFML](https://www.sfml-dev.org/index.php)
-> Run the Makefile in the folder to compile and then run the game.
-> Run test_runner to play
# How to Play
-> The user can input the number of players and enemies that they want, then "Enter" to start the game.
-> User can press "W" to attack and press the left or right arrow to choose which enemy to attack
-> User can enter "space" or "Esc" to end or save the game




















Action Handler: Thi
s file contains the logic for handling various actions that can be performed in the game, such as moving a character, attacking an enemy, or using a spell.

Button: This file defines a Button class used for creating interactive buttons in the game’s user interface, such as those found in menus.

CombatLoop: This file contain the main loop for combat sequences in the game, controlling the flow of turns between the player and enemies.

Knight, Warrior: These files define various types of player characters that can be played in the game. Each file would define the characteristics and behaviors specific to that type of player.

Ghost, Zombie: These files define various types of enemy characters that the player might encounter in the game. Each file would define the characteristics and behaviors specific to that type of enemy.

Entity: This file defines a base Entity class that represents a character in the game. Other character classes, such as Player and the Enemy will inherit from this base class.

EntitySprite: This file is responsible for managing the visual representation of entities in the game.

GameBoard: This file represents the game world, including the layout of the terrain and the placement of characters.

Menu: This file handles the game’s menus, allowing players to make selections, to make a new game or continue to play the saved previous progress.

Enemy, Player: This file defines the Player/Enemy class, representing the player’s characters and the enemy characters in the game. It might include attributes for the player’s stats, inventory, and current state.

Save: This file contains functionality for saving and loading game progress.

Spell: This file defines a Spell class for magical abilities that characters can use in the game.
